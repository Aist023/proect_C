#include <iostream>
#include <Windows.h>
#include <time.h>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <thread>

using namespace std;


void print_k(int x0, int y0, int x1, int y1, int r, HDC hDC, COLORREF color) {
    POINT op;
    MoveToEx(hDC, x0, y0 - 1, &op);
    SelectObject(hDC, CreatePen(0, 49, color));
    int r1 = r - 24;
    for (int i = 0; i < 720; i++) {
        x1 = x0 + r1 * cos(i);
        y1 = y0 + r1 * sin(i);
        MoveToEx(hDC, x0, y0, &op);
        LineTo(hDC, x1, y1);
    }
}
void print_l(int x0, int y0, int x1, int y1, int r, int dl,HDC hDC, COLORREF color) {
    POINT op;
    MoveToEx(hDC, x0, y0, &op);
    x1 = x0 + 10;
    y1 = y0  + 24;
    y0 = y0 + 12;
    SelectObject(hDC, CreatePen(0, 32, color));
    for (int i = 0; i < r*2/24; i++) {
        x1=x1-24;
        if (i == 2) {
            x1--;
        }
        MoveToEx(hDC, x1, y0, &op);
        LineTo(hDC, x1, y1+dl+30);
    }
    x1 = x0 + 1;
    y0 = y0 - 12;
    y1 = y0 - 4;
    SelectObject(hDC, CreatePen(0, 1, color));
    for (int i = 0; i < 20; i++) {
        y1++;
        MoveToEx(hDC, x0, y1, &op);
        LineTo(hDC, x1-r*2-1, y1);
    }
}
void print_penis() {
    POINT op;
    COLORREF color1 = RGB(212, 165, 136), color2 = RGB(223, 128, 122), color3 = RGB(1, 1, 1);
    HWND hWnd = GetConsoleWindow();
    HDC hDC = GetDC(hWnd);
    SelectObject(hDC, GetStockObject(WHITE_PEN));
    int x0 = 250, y0 = 100, r = 75, dl = 270;
    int x1=0, y1=0;
    print_k(x0, y0, x1, y1, r, hDC, color2);
    x1 = x0 + 5;
    y1 = y0 - r - 1;
    MoveToEx(hDC, x0, y0, &op);
    for (int i = 0; i < 25; i++) {
        y1++;
        for (int j = 0; j < 10; j++) {
            x1--;
            SetPixel(hDC, x1, y1, color3);
        }
        x1 = x0 + 5;
    }
    x0 = x0 + r - 1;
    y0 = y0 + dl;
    print_k(x0, y0, x1, y1, r, hDC, color1);
    x0 = x0 - r * 2;
    print_k(x0, y0, x1, y1, r, hDC, color1);
    y0 = y0 - dl;
    x0 = x0+ r * 2;
    print_l(x0, y0, x1, y1, r, dl, hDC, color1);
    ReleaseDC(hWnd, hDC);
}
void print(int cam, int yl, int cenyl, int au, int cenau) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < 34; i++) {
        if (i%5 == 0 && i < 29) {
            SetConsoleTextAttribute(hConsole, 16 * 3+4);
            for (int i = 0; i < 31; i++) {
                cout << "<>";
            }
            SetConsoleTextAttribute(hConsole, 16 * 3);
            cout << "\n";
        }
        else if (i % 5 == 1 && i < 29) {
            SetConsoleTextAttribute(hConsole, 16 * 3 + 1);
            for (int i = 0; i < 31; i++) {
                cout << "<>";
            }
            SetConsoleTextAttribute(hConsole, 16 * 3);
            cout << "\n";
        }
        else if (i % 5 == 2 && i < 29) {
            SetConsoleTextAttribute(hConsole, 16 * 3 + 6);
            for (int i = 0; i < 31; i++) {
                cout << "<>";
            }
            SetConsoleTextAttribute(hConsole, 16 * 3);
            cout << "\n";
        }
        else if (i % 5 == 3 && i < 29) {
            SetConsoleTextAttribute(hConsole, 16 * 3 + 8);
            for (int i = 0; i < 31; i++) {
                cout << "<>";
            }
            SetConsoleTextAttribute(hConsole, 16 * 3);
            cout << "\n";
        }
        else if (i % 5 == 4 && i < 29) {
            SetConsoleTextAttribute(hConsole, 16 * 3 + 14);
            for (int i = 0; i < 31; i++) {
                cout << "<>";
            }
            SetConsoleTextAttribute(hConsole, 16 * 3);
            cout << "\n";
        }
        else if (i == 29) {
            SetConsoleTextAttribute(hConsole, 16 * 0+7);
            cout << "\n";
            cout << "\t|+; q-"<<yl<<"|";
            cout << "|цена-" << cenyl << "|";
            SetConsoleTextAttribute(hConsole, 16 * 13);
        }
        /*else if (i == 31) {
            SetConsoleTextAttribute(hConsole, 16 * 0 + 7);
            cout << "\t|^; e-" << au << "|";
            cout << "|цена-" << cenau << "|";
            SetConsoleTextAttribute(hConsole, 16 * 13);
        }*/
        else if (i == 33) {
            cout << "\t\t\t    CAM-" << cam ;
        }
        else {
            cout << "\n";
        }
    }
    print_penis();
}

/*void avto(int& cam, int& au, int& p) {
    while (true) {
        if (au > 0) {
            p = 1;
            cam = cam + au;
            Sleep(3000);
            p = 0;
            int cam2=cam-1, n = 1;
            while ((cam2 /= 10) > 0) n++;
            for (int i = 0; i < n; i++) {
                printf("\b ");
                printf("\b");
            }
            cout << cam;
        }
    }
}*/

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("mode con cols=62 lines=35");
    int z=' ';
    int cam = 0, cam2 = 0, yl = 1, cenyl = 10, au = 0, cenau = 50, p = 0;
    //thread t(avto, std::ref(cam), std::ref(au), std::ref(p));
    
    do{
        SetConsoleTextAttribute(hConsole, 16 * 13);
        cout << "                           DickClick                          \n";
        SetConsoleTextAttribute(hConsole, 16 * 3);
        print(cam, yl, cenyl, au, cenau);
        z = 0;
        if (_kbhit()) {
            system("cls");
            cout << "\t\t\t   DickClick\n";
            print(cam, yl, cenyl, au, cenau);
            Sleep(1000);
            system("pause");
        }
        else {
            z = _getch();
        }
        Sleep(100);
        switch (z){
        case ' ':
            system("cls"); 
            if (p==1) {
                cam += yl;
            }
            else {
                cam += yl - au;
            }
            cam2 += yl;
            break;
        case 'q':
            if (cam >= cenyl) {
                yl++;
                cam -= cenyl;
                cenyl = cenyl * 2;
            }
            system("cls");
            break;
        case 'e':
            if (cam >= cenau) {
                au++;
                cam -= cenau;
                cenau = cenau * 2;
            }
            system("cls");
            break;
        }
        system("cls");
    } while (z!='v');
    //t.detach();
    return 0;
}