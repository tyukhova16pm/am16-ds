#include <iostream>
#include <fstream>
#include <vector>

char koi8[256];
char win1251[256];
char utf8[65536];
unsigned char codesKoiToWin[256];
unsigned char codesWinToKoi[256];
unsigned short int codesKoiToUTF[256]; // лень париться с ними, поэтому пусть будут здесь
unsigned short int codesWinToUTF[256];

int IdentifyEncoding (const std::vector<unsigned char> input); // 0 - unknown, 1 - koi8, 2 - win1251
unsigned char most_frequent_symbol    (const std::vector<unsigned char> input);

std::vector<unsigned short int> * ConvertFromKoi8ToUTF8 (const std::vector<unsigned char> koi_input);
std::vector<unsigned short int> * ConvertFromWin1251ToUTF8 (const std::vector<unsigned char> win_input);
std::vector<unsigned char> * ConvertFromWin1251ToKoi8 (const std::vector<unsigned char> win_input);
std::vector<unsigned char> * ConvertFromKoi8ToWin1251 (const std::vector<unsigned char> koi_input);

void convert_to_UTF_and_print_into_file (const std::vector<unsigned char> input, std::ofstream & out, int encoding);

int main ()
{
	/////------------------------------| Подготовочная часть |------------------------------/////

	//system ("chcp 1251"); // включаем для отладки в винде.

	for (int i = 0; i < 256; ++i) {
		koi8[i] = 0;
		win1251[i] = 0;
	}
	for (int i = 0; i < 65536; ++i) {
		utf8[i] = 0;
	}

	koi8[0xA3] = 'ё';	koi8[0xB3] = 'Ё';

	koi8[0xC0] = 'ю'; 	koi8[0xC1] = 'а';	koi8[0xC2] = 'б';	koi8[0xC3] = 'ц';
	koi8[0xC4] = 'д';	koi8[0xC5] = 'е';	koi8[0xC6] = 'ф';	koi8[0xC7] = 'г';
	koi8[0xC8] = 'х';	koi8[0xC9] = 'и';	koi8[0xCA] = 'й';	koi8[0xCB] = 'к';
	koi8[0xCC] = 'л';	koi8[0xCD] = 'м';	koi8[0xCE] = 'н';	koi8[0xCF] = 'о';
	koi8[0xD0] = 'п';	koi8[0xD1] = 'я';	koi8[0xD2] = 'р';	koi8[0xD3] = 'с';
	koi8[0xD4] = 'т';	koi8[0xD5] = 'у';	koi8[0xD6] = 'ж';	koi8[0xD7] = 'в';
	koi8[0xD8] = 'ь';	koi8[0xD9] = 'ы';	koi8[0xDA] = 'з';	koi8[0xDB] = 'ш';
	koi8[0xDC] = 'э';	koi8[0xDD] = 'щ';	koi8[0xDE] = 'ч';	koi8[0xDF] = 'ъ';

	koi8[0xE0] = 'Ю';	koi8[0xE1] = 'А';	koi8[0xE2] = 'Б';	koi8[0xE3] = 'Ц';
	koi8[0xE4] = 'Д';	koi8[0xE5] = 'Е';	koi8[0xE6] = 'Ф';	koi8[0xE7] = 'Г';
	koi8[0xE8] = 'Х';	koi8[0xE9] = 'И';	koi8[0xEA] = 'Й';	koi8[0xEB] = 'К';
	koi8[0xEC] = 'Л';	koi8[0xED] = 'М';	koi8[0xEE] = 'Н';	koi8[0xEF] = 'О';
	koi8[0xF0] = 'П';	koi8[0xF1] = 'Я';	koi8[0xF2] = 'Р';	koi8[0xF3] = 'С';
	koi8[0xF4] = 'Т';	koi8[0xF5] = 'У';	koi8[0xF6] = 'Ж';	koi8[0xF7] = 'В';
	koi8[0xF8] = 'Ь';	koi8[0xF9] = 'Ы';	koi8[0xFA] = 'З';	koi8[0xFB] = 'Ш';
	koi8[0xFC] = 'Э';	koi8[0xFD] = 'Щ';	koi8[0xFE] = 'Ч';	koi8[0xFF] = 'Ъ';

	win1251[0xA8] = 'Ё'; win1251[0xB8] = 'ё';
	for (int i = 0; i < 32; ++i) {
		win1251[0xC0 + i] = 'Б' + i - 1;
		win1251[0xE0 + i] = 'б' + i - 1;
	}

	utf8[0xD001] = 'Ё'; utf8[0xD191] = 'ё';
	for (int i = 0; i < 16; ++i) {
		utf8[0xD090 + i] = 'Б' + i - 1;
		utf8[0xD0B0 + i] = 'б' + i - 1;
	}
	for (int i = 0; i < 16; ++i) {
		utf8[0xD090 + i + 16] = 'Р' + i;
		utf8[0xD180 + i] = 'р' + i; // т.к. маленькие буквы лежат неровно, делаем два цикла
	}

	for (int i = 0; i < 0xC0; ++i) { // символы ASCII и нерусскую часть остального не меняем, т.к. хз во что.
		codesKoiToWin[i] = i;
		codesWinToKoi[i] = i;
	}
	for (int i_win = 0x80; i_win <= 0xFF; ++i_win) { // составляем таблицу перевода KOI в Win
		for (int i_koi = 0x80; i_koi <= 0xFF; ++i_koi) {
			if (koi8[i_koi] == win1251[i_win]) {
				codesKoiToWin[i_koi] = i_win;
				codesWinToKoi[i_win] = i_koi;
			}
		}
	}
	
	for (int i = 0; i < 0xC0; ++i) { // символы ASCII и нерусскую часть остального не меняем, т.к. хз во что.
		codesWinToUTF[i] = i;
		codesKoiToUTF[i] = i;
	}
	for (int i_win = 0x80; i_win <= 0xFF; ++i_win) { // составляем таблицу перевода в UTF-8
		for (int i_utf = 0xD090; i_utf <= 0xD18F; ++i_utf) {
			if (utf8[i_utf] == win1251[i_win]) {
				codesWinToUTF[i_win] = i_utf;
				codesKoiToUTF[codesWinToKoi[i_win]] = i_utf;
			}
		}
	}
	codesKoiToUTF[0xA3] = 0xD191; codesKoiToUTF[0xB3] = 0xD001;
	codesWinToUTF[0xB8] = 0xD191; codesWinToUTF[0xA8] = 0xD001; // буква ё

	/////------------------------------| Подготовочная часть закончена |------------------------------/////

	std::ifstream text ("disp.txt", std::ifstream::binary);
	if (!text.is_open()) {
		throw std::runtime_error ("нет файла со вводом");
	}
	std::ofstream output ("result.txt", std::ofstream::binary);
	std::vector<unsigned char> input;
	std::string fromfile;
	//std::cout << "done\n";

	char c;
	while (text.get (c)) {
		fromfile.push_back (c); // читаем в строку
	}
	//std::cout << std::endl;
	const char * chars = fromfile.data ();
	const unsigned char* data_bytes = reinterpret_cast<const unsigned char*>(chars); // переводим эту строку в unsigned char

	//std::cout << "done\n";
	for (int i = 0; i < fromfile.size (); ++i) {
		input.push_back (data_bytes[i]); // для перекодировок хочу векторы.
		//std::cout << koi8[codesWinToKoi[data_bytes[i]]] << win1251[data_bytes[i]] << std::endl;
	}

	std::vector<unsigned char> * converted;
	std::vector<unsigned char> * new_inputKoiToWin;
	std::vector<unsigned char> * new_inputWinToKoi;
	int encoding = IdentifyEncoding (input);
	if (encoding != 0) { // сходу определили кодировку
		convert_to_UTF_and_print_into_file (input, output, encoding);
	}
	else {
		new_inputKoiToWin = &input;
		new_inputWinToKoi = &input;
		for (int i = 0; i < 3; ++i) {
			converted = ConvertFromKoi8ToWin1251 (*new_inputKoiToWin);
			if (i > 0) { // обычный input удалять не хотим
				delete new_inputKoiToWin;
			}
			new_inputKoiToWin = converted;
			encoding = IdentifyEncoding (*new_inputKoiToWin);
			if (encoding != 0) {
				convert_to_UTF_and_print_into_file (*new_inputKoiToWin, output, encoding);
				if (i > 0) {
					delete new_inputKoiToWin;
				}
				break;
			}

			converted = ConvertFromWin1251ToKoi8 (*new_inputWinToKoi);
			if (i > 0) { // обычный input удалять не хотим
				delete new_inputWinToKoi;
			}
			new_inputWinToKoi = converted;
			encoding = IdentifyEncoding (*new_inputWinToKoi);
			if (encoding != 0) {
				convert_to_UTF_and_print_into_file (*new_inputWinToKoi, output, encoding);
				if (i > 0) {
					delete new_inputWinToKoi;
				}
				break;
			}
		}
	}

	text.close ();
	output.close ();
	std::cin >> c;

	return 0;
}

std::vector<unsigned char> * ConvertFromKoi8ToWin1251 (const std::vector<unsigned char> koi_input) {
	std::vector<unsigned char> * result = new std::vector<unsigned char>;
	for (int i = 0; i < koi_input.size (); ++i) {
		result->push_back (codesKoiToWin[koi_input[i]]);
	}
	return result;
}

std::vector<unsigned char> * ConvertFromWin1251ToKoi8 (const std::vector<unsigned char> win_input)
{
	std::vector<unsigned char> * result = new std::vector<unsigned char>;
	for (int i = 0; i < win_input.size (); ++i) {
		result->push_back (codesWinToKoi[win_input[i]]);
	}
	return result;
}

std::vector<unsigned short int> * ConvertFromKoi8ToUTF8 (const std::vector<unsigned char> koi_input)
{
	std::vector<unsigned short int> * result = new std::vector<unsigned short int>;
	for (int i = 0; i < koi_input.size (); ++i) {
		result->push_back (codesKoiToUTF[koi_input[i]]);
	}
	return result;
}

std::vector<unsigned short int> * ConvertFromWin1251ToUTF8 (const std::vector<unsigned char> win_input)
{
	std::vector<unsigned short int> * result = new std::vector<unsigned short int>;
	for (int i = 0; i < win_input.size (); ++i) {
		result->push_back (codesWinToUTF[win_input[i]]);
	}
	return result;
}

int IdentifyEncoding (const std::vector<unsigned char> input) { // 0 - unknown, 1 - koi8, 2 - win1251
	unsigned char mfs = most_frequent_symbol (input);
	if ('о' == koi8[mfs]) {
		//std::cout << 1 << ' ' << mfs << ";\n";
		return 1;
	}
	else if ('о' == win1251[mfs]) {
		//std::cout << 2 << ' ' << mfs << ";\n";
		return 2;
	}
	else {
		//std::cout << 0 << ' ' << mfs << ";\n";
		return 0;
	}
}

unsigned char most_frequent_symbol (const std::vector<unsigned char> input) {
	int symb_count[256];
	unsigned char most_frequent_one = 0xC0;
	int amount;

	for (int i = 0; i < 0xFF; ++i) {
		symb_count[i] = 0;
	}
	for (int i = 0; i < input.size (); ++i) {
		if (input[i] < 0x80) { // символы ASCII нас не интересуют
			continue;
		}
		++symb_count[input[i]];
	} // собираем статистику

	for (int i = 0xC0; i < 0xFF; ++i) {
		if (symb_count[i] > symb_count[most_frequent_one]) {
			most_frequent_one = i;
		}
	}
	return most_frequent_one;
}

void convert_to_UTF_and_print_into_file (const std::vector<unsigned char> input, std::ofstream & out, int encoding)
{
	std::vector<unsigned short int> * converted;
	switch (encoding) {
		case 1:
			converted = ConvertFromKoi8ToUTF8 (input);
			break;
		case 2:
			converted = ConvertFromWin1251ToUTF8 (input);
			break;
		default:
			return; // кидаться ничем не буду, потому что больно
	}
	for (int i = 0; i < converted->size (); ++i) {
		if ((*converted)[i] <= 0xFF ) { // однобайтовое == ASCII
			out.put ((char)(*converted)[i]);
		}
		else { // двухбайтовые символы
			out.put ((char)(((*converted)[i] & 0xFF00) >> 8)); // первый байт
			out.put ((char)(((*converted)[i] & 0x00FF)     )); // второй байт
		}
	}
	delete converted;
}