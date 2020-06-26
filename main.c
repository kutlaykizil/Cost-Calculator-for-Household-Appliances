/*
* MIT License

* Copyright (c) 2020 Kutlay KIZIL

* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:

* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.

* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//Structures
struct Devices
{
   char     nameofdevice[50];
   float    watt;
};
struct Prices
{
   char     Nameofdevice[50];
   float    RealPrice[3];
};

//Colours
void red() 
{
    printf("\033[1;31m");   //Bold
}
void green() 
{
    printf("\033[0;32m");
}
void yellow() 
{
    printf("\033[0;33m");
}
void colourreset()
{
    printf("\033[0m");
}

//Tips
char tip[6][80]=
{
    "Turn off standby appliances",
    "Buy efficient appliances",
    "Wash clothes at a lower temperature",
    "Switch to LEDs",
    "Install a programmable or smart thermostat",
    "Even when idle, devices use energy, accounting for 23% of total home energy use",
};

//Main
int main(void)
{
    start:;
    int threeselect, timing;
    float singlephase, three1, three2, three3;
    green(), printf("Hello! This program let's you calculate the cost of electricity for some of the household appliances you might have in your home.\n\n"), colourreset();
    srand(time(0));
    printf("Tip of the day: %s\n\n", tip[rand() % 6]);
    yellow(), printf("Choose your tariff group for your household.\n1-Single Phase\n2-Three Phase\n> "), colourreset();
    char phaseinput[10];
    phasechoose:;
    scanf("%s", phaseinput);
    timing = atoi(phaseinput);
    switch (timing)
    {
    case 1:
        yellow(), printf("Write the price of 1 kW/h electricity for your area (write '0' for standard value(~0.57)).\n> "), colourreset();
        char singlephaseinput[10];
        scanf("%s", singlephaseinput);
        singlephase = atoi(singlephaseinput);
        if (singlephase == 0)
        {
            singlephase = 0.574033;
        }
        break;

    case 2:
        yellow(), printf("1-) Enter the prices for 1 kW/h electricity for your household.\n2-) Automatically put standard values (day ~0.55, dwelling ~0.8, night ~0.45)\n"), colourreset();
        char threephaseinput[10];
        threephase:;
        scanf("%s", threephaseinput);
        threeselect = atoi(threephaseinput);
        switch (threeselect)
        {
        case 1:
            printf("Price for times between 06:00 - 17:00\n> ");
            scanf("%f", &three1);
            printf("Price for times between 17:00 - 22:00\n> ");         
            scanf("%f", &three2);
            printf("Price for times between 22:00 - 06:00\n> ");
            scanf("%f", &three3);
            break;

        case 2:
            three1 = 0.5445;
            three2 = 0.7997;
            three3 = 0.4522;
            break;

        default:
            red(), printf("Enter a correct value!\n> "), colourreset();
            goto threephase;
            break;
        }
        break;

    default:
        red(), printf("Enter a correct value!\n> "), colourreset();
        goto phasechoose;
        break;
    }
    struct Prices price[13];
    struct Devices device[13];
    strcpy (device[0].nameofdevice, "Air Conditioner");
            device[0].watt = 750;
    strcpy (device[1].nameofdevice, "Ceiling Fan");
            device[1].watt = 65;
    strcpy (device[2].nameofdevice, "Coffee Maker");
            device[2].watt = 900;
    strcpy (device[3].nameofdevice, "Food Blender");
            device[3].watt = 390;
    strcpy (device[4].nameofdevice, "Iron");
            device[4].watt = 1000;
    strcpy (device[5].nameofdevice, "Microwave Owen");
            device[5].watt = 1000;
    strcpy (device[6].nameofdevice, "Toaster");
            device[6].watt = 1150;
    strcpy (device[7].nameofdevice, "Vacuum Cleaner");
            device[7].watt = 800;
    strcpy (device[8].nameofdevice, "Water Heater");
            device[8].watt = 3800;
    strcpy (device[9].nameofdevice, "Television");
            device[9].watt = 100;
    strcpy (device[10].nameofdevice, "Fridge");
            device[10].watt = 150;
    strcpy (device[11].nameofdevice, "Dishwasher");
            device[11].watt = 1200;
    strcpy (device[12].nameofdevice, "Washing Machine");
            device[12].watt = 500;

    green(), printf("Now you will be asked for few devices to add in your list, you can enter their wattage manually, otherwise an average value will be given.\n"), colourreset();
    int order = 0, answer, i;
    for (i = 0; i < 13; i++)
    {
        skip:;
        yellow(), printf("Do you want to add %s?\n1-) Yes\n2-) No\n> ", device[i].nameofdevice), colourreset();
        char deviceinput[10];
        devicechoose:;
        scanf("%s", deviceinput);
        answer = atoi(deviceinput);
        if (answer == 1)
        {
            int what;
            float wattage;
            yellow(), printf("Do you want to enter a specific Wattage value for %s (Default is %.fW).\n1-) Yes\n2-) No\n> ", device[i].nameofdevice, device[i].watt), colourreset();
            char wattinput[10];
            wattphase:;
            scanf("%s", wattinput);
            what = atoi(wattinput);
            switch (what)
            {
                case 1:
                    printf("Please write how much wattage your device uses.\n> ");
                    scanf("%f", &wattage);
                    break;

                case 2:
                    wattage = device[i].watt;
                    break;

                default:
                    red(), printf("Enter a correct value!\n> "), colourreset();
                    goto wattphase;
                    break;
            }
            float duration, duration1, duration2, duration3;
            if (timing == 1)
            {
                printf("How many hours do you use your %s in a day?\n> ", device[i].nameofdevice);
                scanf("%f", &duration);
                strcpy (price[order].Nameofdevice, device[i].nameofdevice);
                price[order].RealPrice[0] = ((wattage/1000)*duration*30)*singlephase;
                order++;
            }
            else
            {
                printf("How many hours do you use your %s between 06:00 - 17:00\n> ", device[i].nameofdevice);
                scanf("%f", &duration1);
                strcpy (price[order].Nameofdevice, device[i].nameofdevice);
                price[order].RealPrice[0] = ((wattage/1000)*duration1*30)*three1;
                printf("How many hours do you use your %s between 17:00 - 22:00\n> ", device[i].nameofdevice);
                scanf("%f", &duration2);
                strcpy (price[order].Nameofdevice, device[i].nameofdevice);
                price[order].RealPrice[1] = ((wattage/1000)*duration2*30)*three2;
                printf("How many hours do you use your %s between 22:00 - 06:00\n> ", device[i].nameofdevice);
                scanf("%f", &duration3);
                strcpy (price[order].Nameofdevice, device[i].nameofdevice);
                price[order].RealPrice[2] = ((wattage/1000)*duration3*30)*three3;
                order++;
            }
        }
        else if (answer == 2 && i < 13)
        {
            if (i != 12)
            {
                i++;
                goto skip;
            }
            else
            {
                goto endloop;
            }       
        }
        else
        {
            red(), printf("Enter a correct value!\n> "), colourreset();
            goto devicechoose;
        }
    }
    endloop:;

    if (timing == 1)
    {
        printf("\nName  |   Price for one month usage\n");
        for (i = 0; i < order; i++)
        {
            printf("\n%s    |   %.2f TL\n", price[i].Nameofdevice, price[i].RealPrice[0]);
        }
    }
    else
    {
        printf("\nName  |   Price inside 06-12 |    Price inside 06-12 |    Price inside 06-12\n");
        for (i = 0; i < order; i++)
        {
            printf("\n%s  |   %.2f  |  %.2f  |  %.2f\n", price[i].Nameofdevice, price[i].RealPrice[0], price[i].RealPrice[1], price[i].RealPrice[2]);  
        }
    }
    yellow(), printf("\nDo you want to start again?\n1-) Yes\n2-) No\n>"), colourreset();
    char startagain[10];
    startagainagain:;
    scanf("%s", startagain);
    int loop = atoi(startagain);
    switch (loop)
    {
    case 1:
        printf("\nRestarting...\n\n");
        goto start;
        break;
    
    case 2:
        printf("\nGoodbye^^\n");
        break;
    
    default:
        red(), printf("Enter a correct value!\n> "), colourreset();
        goto startagainagain;
        break;
    }
    return 0;
}