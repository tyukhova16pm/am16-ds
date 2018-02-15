#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int koi8_key[] = {
    239,
    207,
    229,
    197,
    225,
    193,
    233,
    201,
    206,
    238,
    244,
    212,
    243,
    211,
    236,
    204,
    247,
    215,
    242,
    210,
    203,
    235,
    228,
    196,
    237,
    205,
    245,
    213,
    240,
    208,
    241,
    209,
    216,
    248,
    249,
    217,
    231,
    199,
    250,
    218,
    226,
    194,
    254,
    222,
    202,
    234,
    246,
    214,
    251,
    219,
    232,
    200,
    224,
    192,
    227,
    195,
    221,
    253,
    252,
    220,
    230,
    198,
    255,
    223
};

int win1251_key[] = {
    206,
    238,
    197,
    229,
    192,
    224,
    200,
    232,
    237,
    205,
    210,
    242,
    209,
    241,
    203,
    235,
    194,
    226,
    208,
    240,
    234,
    202,
    196,
    228,
    204,
    236,
    211,
    243,
    207,
    239,
    223,
    255,
    252,
    220,
    219,
    251,
    195,
    227,
    199,
    231,
    193,
    225,
    215,
    247,
    233,
    201,
    198,
    230,
    216,
    248,
    213,
    245,
    222,
    254,
    214,
    246,
    249,
    217,
    221,
    253,
    212,
    244,
    218,
    250
};

int utf8_key[64][2] = {
    {208, 158},
    {208, 190},
    {208, 149},
    {208, 181},
    {208, 144},
    {208, 176},
    {208, 152},
    {208, 184},
    {208, 189},
    {208, 157},
    {208, 162},
    {209, 130},
    {208, 161},
    {209, 129},
    {208, 155},
    {208, 187},
    {208, 146},
    {208, 178},
    {208, 160},
    {209, 128},
    {208, 186},
    {208, 154},
    {208, 148},
    {208, 180},
    {208, 156},
    {208, 188},
    {208, 163},
    {209, 131},
    {208, 159},
    {208, 191},
    {208, 175},
    {209, 143},
    {209, 140},
    {208, 172},
    {208, 171},
    {209, 139},
    {208, 147},
    {208, 179},
    {208, 151},
    {208, 183},
    {208, 145},
    {208, 177},
    {208, 167},
    {209, 135},
    {208, 185},
    {208, 153},
    {208, 150},
    {208, 182},
    {208, 168},
    {209, 136},
    {208, 165},
    {209, 133},
    {208, 174},
    {209, 142},
    {208, 166},
    {209, 134},
    {209, 137},
    {208, 169},
    {208, 173},
    {209, 141},
    {208, 164},
    {209, 132},
    {208, 170},
    {209, 138}
};


double koi8_dispers[] = {
    0.095249209893009,
    0.095249209893009,
    0.06836817536026,
    0.06836817536026,
    0.067481298384992,
    0.067481298384992,
    0.055995027400041,
    0.055995027400041,
    0.052242744063325,
    0.052242744063325,
    0.048259227579808,
    0.048259227579808,
    0.044373930818522,
    0.044373930818522,
    0.041607469048102,
    0.041607469048102,
    0.037182869900548,
    0.037182869900548,
    0.036257574878947,
    0.036257574878947,
    0.027272101249674,
    0.027272101249674,
    0.024573052277538,
    0.024573052277538,
    0.023654281075125,
    0.023654281075125,
    0.022505001594711,
    0.022505001594711,
    0.020093363101279,
    0.020093363101279,
    0.017963698570559,
    0.017963698570559,
    0.016236698657543,
    0.016236698657543,
    0.016152251442489,
    0.016152251442489,
    0.016038809475485,
    0.016038809475485,
    0.014150888689147,
    0.014150888689147,
    0.01362825828525,
    0.01362825828525,
    0.011749760793296,
    0.011749760793296,
    0.0097143292064136,
    0.0097143292064136,
    0.0087973701759981,
    0.0087973701759981,
    0.0076538896459741,
    0.0076538896459741,
    0.0070917538925454,
    0.0070917538925454,
    0.00510996259677,
    0.00510996259677,
    0.0029893589260344,
    0.0029893589260344,
    0.0024649163501406,
    0.0024649163501406,
    0.002252892226507,
    0.002252892226507,
    0.0015961610948418,
    0.0015961610948418,
    0.00001,
    0.00001
};

double win1251_dispers[] = {
    0.095249209893009,
    0.095249209893009,
    0.06836817536026,
    0.06836817536026,
    0.067481298384992,
    0.067481298384992,
    0.055995027400041,
    0.055995027400041,
    0.052242744063325,
    0.052242744063325,
    0.048259227579808,
    0.048259227579808,
    0.044373930818522,
    0.044373930818522,
    0.041607469048102,
    0.041607469048102,
    0.037182869900548,
    0.037182869900548,
    0.036257574878947,
    0.036257574878947,
    0.027272101249674,
    0.027272101249674,
    0.024573052277538,
    0.024573052277538,
    0.023654281075125,
    0.023654281075125,
    0.022505001594711,
    0.022505001594711,
    0.020093363101279,
    0.020093363101279,
    0.017963698570559,
    0.017963698570559,
    0.016236698657543,
    0.016236698657543,
    0.016152251442489,
    0.016152251442489,
    0.016038809475485,
    0.016038809475485,
    0.014150888689147,
    0.014150888689147,
    0.01362825828525,
    0.01362825828525,
    0.011749760793296,
    0.011749760793296,
    0.0097143292064136,
    0.0097143292064136,
    0.0087973701759981,
    0.0087973701759981,
    0.0076538896459741,
    0.0076538896459741,
    0.0070917538925454,
    0.0070917538925454,
    0.00510996259677,
    0.00510996259677,
    0.0029893589260344,
    0.0029893589260344,
    0.0024649163501406,
    0.0024649163501406,
    0.002252892226507,
    0.002252892226507,
    0.0015961610948418,
    0.0015961610948418,
    0.00001,
    0.00001
};


int identify_encoding(unsigned char* text)
{
    int i, j;
    double koi8_val = 0;
    double win1251_val = 0;
    for(i=0; i<strlen(text); ++i)
    {
        if(text[i] > 190)
        {
            for(j=0; j<64; ++j)
            {
                if(text[i] == koi8_key[j])
                {
                    koi8_val += koi8_dispers[j];
                }
                else if(text[i] == win1251_key[j])
                {
                    win1251_val += win1251_dispers[j];
                }
            }
        }
    }
    if(koi8_val > win1251_val && koi8_val/strlen(text) > 0.033) return 8;
    else if(win1251_val > koi8_val && win1251_val/strlen(text) > 0.033) return 1251;
    else return 0;
}

void koi8_to_win1251(unsigned char* koi8, unsigned char* win1251)
{
    int i, j;
    for(i=0; i<strlen(koi8); ++i)
    {
        if(koi8[i] > 190)
        {
            for(j=0; j<64; ++j)
            {
                if(koi8[i] == koi8_key[j])
                {
                    win1251[i] = win1251_key[j];
                    break;
                }
            }
        }
        else {
            win1251[i] = koi8[i];
        }
    }
}

void win1251_to_koi8(unsigned char* win1251, unsigned char* koi8)
{
    int i, j;
    for(i=0; i<strlen(win1251); ++i)
    {
        if(win1251[i] > 190)
        {
            for(j=0; j<64; ++j)
            {
                if(win1251[i] == win1251_key[j])
                {
                    koi8[i] = koi8_key[j];
                    break;
                }
            }
        }
        else {
            koi8[i] = win1251[i];
        }
    }
}

void win1251_to_utf8(unsigned char* win1251, unsigned int **utf8)
{
    int i, j;
    for(i=0; i<strlen(win1251); ++i)
    {
        if(win1251[i] > 190)
        {
            for(j=0; j<64; ++j)
            {
                if(win1251[i] == win1251_key[j])
                {
                    utf8[i][0] = utf8_key[j][0];
                    utf8[i][1] = utf8_key[j][1];
                    break;
                }
            }
        }
        else {
            utf8[i][0] = win1251[i];
        }
    }
}

void koi8_to_utf8(unsigned char* koi8, unsigned int **utf8)
{
    int i, j;
    for(i=0; i<strlen(koi8); ++i)
    {
        if(koi8[i] > 190)
        {
            for(j=0; j<64; ++j)
            {
                if(koi8[i] == koi8_key[j])
                {
                    utf8[i][0] = utf8_key[j][0];
                    utf8[i][1] = utf8_key[j][1];
                    break;
                }
            }
        }
        else {
            utf8[i][0] = koi8[i];
        }
    }
}

int decode(unsigned char* source, unsigned int** utf8, int deep)
{
    int encK = identify_encoding(source);
    if(encK == 8)
    {
        koi8_to_utf8(source, utf8);
        return 1;
    }
    else if(encK == 1251)
    {
        win1251_to_utf8(source, utf8);
        return 1;
    }
    int encW = encK;
    if(deep > 3) return 0;
    int lenOfText = strlen(source);
    unsigned char* koi = (unsigned char*)malloc(sizeof(unsigned char)*lenOfText);
    unsigned char* win = (unsigned char*)malloc(sizeof(unsigned char)*lenOfText);

    koi8_to_win1251(source, win);
    encK = identify_encoding(win);

    win1251_to_koi8(source, koi);
    encW = identify_encoding(koi);
    if(encK == 8 || encW == 8)
    {
        koi8_to_utf8(win, utf8);
        return 1;
    }
    else if(encW == 1251 || encK == 1251)
    {
        win1251_to_utf8(koi, utf8);
        return 1;
    }
    else if(encK == 0 && encW == 0)
    {
        ++deep;
        decode(win, utf8, deep);
        decode(koi, utf8, deep);
    }
}



int main(int argc, char* argv[])
{	
    char inputFile[32];
    char outFile[32];
    if(argc == 3)
    {
        strcpy(inputFile, argv[1]);
        strcpy(outFile, argv[2]);

    }
    else if(argc == 2)
    {
        strcpy(inputFile, argv[1]);
        printf("Default output file is <out.txt>\n");
        strcpy(outFile, "out.txt");
    }
    else {
        printf("Enter input file: ");
        scanf("%s", inputFile);
        strcpy(inputFile, "text.txt");
        printf("Default output file is <out.txt>\n");
        strcpy(outFile, "out.txt");
    }

    unsigned char text[5000];
    FILE *ftxt = fopen(inputFile, "r");
    FILE *out = fopen(outFile, "w");
    int i;
    unsigned int **utf = (unsigned int**)malloc(sizeof(unsigned int*)*sizeof(text));
    for(i=0; i<sizeof(text); i++)
    {
        utf[i] = (unsigned int*)malloc(sizeof(unsigned int)*2);
    }
    int p;
    while(!feof(ftxt)) {
        for(p=0; p<sizeof(text)-1; ++p)
        {
            if(feof(ftxt)) break;
            text[p] = getc(ftxt);
        }

        int lenOfText = strlen(text);

        int deep = 0;
        if(decode(text, utf, deep))
        {
            for(i=0; i<lenOfText; ++i)
            {
                printf("%c%c", utf[i][0], utf[i][1]);
                fputc(utf[i][0], out);
                fputc(utf[i][1], out);
            }
        }
        else {
            perror("Error! Unrecognizable encoding");
        }
    }
}