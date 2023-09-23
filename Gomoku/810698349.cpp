#include <iostream>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <cstdlib>

void Draw_t(char[20][20], int);
void Draw_g(char[20][20], int);
int Check_i1(char[20][20], char, int, int);
int Check_i2(char[20][20], char, int, int, int);
int Check_e(char[20][20], int);
int Check_v(char[20][20], char, int, int, int);
int Check_c(char[20][20], char, int, int, int, int, int);
int Check_f(char[20][20],char, int, int, int, int, int, int );
void Play_tWF(int);
void Play_tWC1(int);
void Play_tWC2(int);
void Play_tWC3(int);

using namespace std;
int main()
{
    int n = 10, input_s1 = 0, input_s2 = 0, input_s3 = 0, c = 0;
    cout << " ** Welcome to Gomoku **" << endl;
    while (true) {

        if (c == 0) {
            cout << endl << "1-Start the gmae" << endl << "2-Choose the size of your board" << endl << "3-Exit" << endl;
            cin >> input_s1;
        }
        else
            input_s1 = 1;
        if (input_s1 != 1 && input_s1 != 2 && input_s1 != 3) {
            cout << "Please select a valid number : " << endl;
                continue;
        }
        cout << endl;
        switch (input_s1) {
        case(3):
            cout << "Have a great time! " << endl;
            c = 1;
            break;
        case(2):
            cout << "Please enter your base size ( Between 7 to 20 ): ";
            cin >> n;
            while (n > 20 || n < 7 ) {
                cout << "Base size must be Between 7 to 20 : ";
                cin >> n;
            }
            cout << endl;
            continue;
            break;
        case(1):
            if (c != 3) {
                cout << "Select your mode: " << endl << "1-Play with friend" << endl << "2-Play with CPU" << endl << "3-Back" << endl;
                cin >> input_s2;
                if (input_s2 == 1) {
                    Play_tWF(n);
                    c = 0;
                }   
                else if (input_s2 == 2 && c != 3) {
                    cout << "Select your level: " << endl << "1-Easy" << endl << "2-Medium" << endl << "3-Hard" << endl << "4-Back" << endl;
                    cin >> input_s3;
                    if (input_s3 == 1) {
                        Play_tWC1(n);
                        c = 0;
                    }   
                    else if (input_s3 == 2) {
                        Play_tWC2(n);
                        c = 0;
                    }
                    else if (input_s3 == 3) {
                        Play_tWC3(n);
                        c = 0;
                    }
                    else if (input_s3 == 4) {
                        c = 2;
                        continue;
                    }
                    else {
                        cout << "Please select a valid number!" << endl;
                        c = 3;
                    }
                }
                else if (input_s2 == 3) {
                    c = 0;
                    continue;
                }
                else {
                    cout << "Please select a valid number!" << endl;
                    c = 2;
                }
            }
            else {
                input_s2 = 2;
                cout << "Select your level: " << endl << "1-Easy" << endl << "2-Medium" << endl << "3-Hard" << endl << "4-Back" << endl;
                cin >> input_s3;
                if (input_s3 == 1) {
                    Play_tWC1(n);
                    c = 0;
                }   
                else if (input_s3 == 2) {
                    Play_tWC2(n);
                    c = 0;
                } 
                else if (input_s3 == 3) {
                    Play_tWC3(n);
                    c = 0;
                }
                else if (input_s3 == 4) {
                    c = 2;
                    continue;
                }
                else {
                    cout << "Please select a valid number!" << endl;
                    c = 3;
                }
            }
            break;
        }
        if (c == 1)
            break;
    }
}

void Draw_t(char Base[20][20], int n)
{
    char A1[21] = "ABCDEFGHIJKLMNOPQRST";
    int A2[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
    cout << "   ";
    for (int i = 0; i < n; i++)
        cout << A1[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (i < 9)
            cout << A2[i] << "  ";
        else
            cout << A2[i] << " ";
        for (int j = 0; j < n; j++)
        {
            cout << Base[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void Draw_g(char Base[20][20], int n)
{
    char A1[21] = "ABCDEFGHIJKLMNOPQRST";
    int A2[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
    
}
int Check_i1(char Base[20][20], char input_t, int Cina1, int n)
{
    int a1 = 1, a2 = 0, c = 1;
    char A1C[21] = "ABCDEFGHIJKLMNOPQRST", A1S[21] = "abcdefghijklmnopqrst";
    char A2C[21], A2S[21];
    strncpy(A2C, A1C, n);
    strncpy(A2S, A1S, n);
    while (true)
    {

        while (Cina1 != a1 && a1 <= n)
            a1++;
        if (a1 > n || a1 == 0) {
            Cina1 = 0;
            input_t = ' ';
            cout << "Please select a valid cell: ";
            c = 0;
            break;
        }

        while (A2C[a2] != input_t && a2 <= n)
            a2++;
        if (a2 > n) {
            a2 = 0;
            while (A2S[a2] != input_t && a2 <= n)
                a2++;
        }
        if (a2 > n) {
            Cina1 = 0;
            input_t = ' ';
            cout << "Please select a valid cell: ";
            c = 0;
            break;
        }
        if (Base[a1 - 1][a2] != '-') {
            Cina1 = 0;
            input_t = ' ';
            cout << "Please select an available cell: ";
            c = 0;
            break;
        }
        break;

    }
    if (c == 0)
        return 0;
    else
        return 1;
}
int Check_i2(char Base[20][20], char input_t, int Cina1, int n,int a)
{
    int a1 = 1, a2 = 0;
    char A1C[21] = "ABCDEFGHIJKLMNOPQRST", A1S[21] = "abcdefghijklmnopqrst";
    char A2C[21], A2S[21];
    strncpy(A2C, A1C, n);
    strncpy(A2S, A1S, n);
    while (Cina1 != a1 && a1 <= n)
        a1++;

    while (A2C[a2] != input_t && a2 <= n)
        a2++;
    if (a2 > n) {
        a2 = 0;
        while (A2S[a2] != input_t && a2 <= n)
            a2++;
    }
   
    if (a == 1)
        return a1;
    else
        return a2;
}
int Check_v(char Base[20][20] ,char t,int n,int x,int y)
{
    int b[4] = { 0 }, i = y - 1, j = x - 1, q = 0, c = 0, d = 0;
    //X
    c = j;
    while (t == Base[i][c] && c<=n) {
        c++;
        q++;
    }
    c = j - 1;
    while (t == Base[i][c] && c >=0) {
        c--;
        q++;
    }
    b[0] = q;
    //y
    q = 0;
    d = i;
    while (t == Base[d][j] && d <= n) {
        d++;
        q++;
    }
    d = i - 1;
    while (t == Base[d][j] && d >= 0) {
        d--;
        q++;
    }
    b[1] = q;
    //xy+
    q = 0;
    c = j;
    d = i;
    while (t == Base[d][c] && c <= n && d>=0) {
        c++;
        d--;
        q++;
    }
    c = j - 1;
    d = i + 1;
    while (t == Base[d][c] && c >= 0 && d<=n) {
        c--;
        d++;
        q++;
    }
    b[2] = q;
    //xy-
    q = 0;
    c = j;
    d = i;
    while (t == Base[d][c] && c <= n && d <= n) {
        c++;
        d++;
        q++;
    }
    c = j - 1;
    d = i - 1;
    while (t == Base[d][c] && c >= 0 && d >= 0) {
        c--;
        d--;
        q++;
    }
    b[3] = q;


    for (q = 0; q < 4; q++) {
        if (5 <= b[q]) {
            c= 1;
            break;
        }
        else
            c= 0;
    }

    if (1 == c)
        return 1;
    else
        return 0;
}
int Check_e(char Base[20][20], int n)
{
    int e = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (Base[i][j] != '-')
                e++;
        }
    if (e == (n * n)) {
        Draw_t(Base, n);
        cout << endl << " ** The game ended in a DRAW **" << endl;
        return 1;
    }
    else
        return 0;
}
int Check_c(char Base[20][20], char t, int n, int x, int y, int a,int m)
{
    char tt;
    int b[4] = { 0 }, i = y - 1, j = x - 1, q = 0, c = 0, d = 0, max = 0, Check[4][2] = { 0 }, error = 0;
    if (t == 'X') {
        tt = 'O';
        max == 0;
    }
    else {
        max = 1;
        tt = 'X';
    }
    //X
    if (m == 2)
        error = -1;
    else if (m == 3)
        error = 0;
    c = j + 1;
    while (t == Base[i][c] && c < n) {
        c++;
        q++;
    }
    if (tt != Base[i][c] || '-' == Base[i][j])
        Check[0][0] = 1;
    if (c >= n && '-' != Base[i][j])
        error ++;
    c = j - 1;
    while (t == Base[i][c] && c >= 0) {
        c--;
        q++;
    }
    if (tt != Base[i][c] || '-' == Base[i][j])
        Check[0][1] = 1;
    if (c < 0 && '-' != Base[i][j])
        error ++;
    if (error >0 ) {
        Check[0][0] = 0;
        Check[0][1] = 0;
    }
    b[0] = q + 1;
    //y
    q = 0;
    if (m == 2)
        error = -1;
    else if (m == 3)
        error = 0;
    d = i + 1;
    while (t == Base[d][j] && d < n) {
        d++;
        q++;
    }
    if (tt != Base[d][j] || '-' == Base[i][j])
        Check[1][0] = 1;
    if (d >= n && '-' != Base[i][j])
        error++;
    d = i - 1;
    while (t == Base[d][j] && d >= 0) {
        d--;
        q++;
    }
    if (tt != Base[d][j] || '-' == Base[i][j])
        Check[1][1] = 1;
    if (d < 0 && '-' != Base[i][j])
        error++;
    if (error > 0) {
        Check[1][0] = 0;
        Check[1][1] = 0;
    }
    b[1] = q + 1;
    //xy+
    q = 0;
    if (m == 2)
        error = -1;
    else if (m == 3)
        error = 0;
    c = j + 1;
    d = i - 1;
    while (t == Base[d][c] && c < n && d >= 0) {
        c++;
        d--;
        q++;
    }
    if (tt != Base[d][c] || '-' == Base[i][j])
        Check[2][0] = 1;
    if ((d < 0 || c>=n ) && '-' != Base[i][j])
        error++;
    c = j - 1;
    d = i + 1;
    while (t == Base[d][c] && c >= 0 && d < n) {
        c--;
        d++;
        q++;
    }
    if (tt != Base[d][c] || '-' == Base[i][j])
        Check[2][1] = 1;
    if ((c < 0 || d >= n) && '-' != Base[i][j])
        error++;
    if (error >0 ) {
        Check[2][0] = 0;
        Check[2][1] = 0;
    }
    b[2] = q + 1;
    //xy-
    q = 0;
    if (m == 2)
        error = -1;
    else if (m == 3)
        error = 0;
    c = j + 1;
    d = i + 1;
    while (t == Base[d][c] && c < n && d < n) {
        c++;
        d++;
        q++;
    }
    if (tt != Base[d][c] || '-' == Base[i][j])
        Check[3][0] = 1;
    if ((c >=n || d >= n) && '-' != Base[i][j])
        error++;
    c = j - 1;
    d = i - 1;
    while (t == Base[d][c] && c >= 0 && d >= 0) {
        c--;
        d--;
        q++;
    }
    if (tt != Base[d][c] || '-' == Base[i][j])
        Check[3][1] = 1;
    if ((c < 0 || d < 0) && '-' != Base[i][j])
        error++;
    if (error >0 ) {
        Check[3][0] = 0;
        Check[3][1] = 0;
    }
    b[3] = q + 1;

    c = 4;
    for (q = 0; q < 4; q++) {
        d = Check[q][0] + Check[q][1];
        if (max < b[q] && d>0) {
            max = b[q];
            c = q;
        }
    }

    if (a == 0) {
        if (0 == c)
            return 0;
        else if (1 == c)
            return 1;
        else if (2 == c)
            return 2;
        else if (3 == c)
            return 3;
        else if (4 == c)
            return 4;
    }
    else if (a == 1)
        return max;
}
int Check_f(char Base[20][20],char t, int n, int ss1, int ss2, int Check,int c,int a)
{
    char tt;
    int s1 = 0, s2=0, q = 1;
    srand(time(0));
    if (t == 'O')
        tt = 'X';
    else
        tt = 'O';


    if (0 == Check) {
        s1 = ss1;
        s2 = ss2;
        while (Base[s1 - 1][s2] != '-' && s2 < n && s2 >= 0) {
            if (c % 2 == 0) {
                s2 = ss2 + q;
                q++;
            }
            else {
                s2 = ss2 - q;
                q++;
            }

        }
        if (s2 >= n || s2 < 0) {
            q = 0;
            s1 = ss1;
            s2 = ss2;
            while (Base[s1 - 1][s2] != '-' && s2 >= 0 && s2 < n) {
                if (c % 2 == 0) {
                    s2 = ss2 - q;
                    q++;
                }
                else {
                    s2 = ss2 + q;
                    q++;
                }

            }
        }
        if (s2 < 0 || s2 >= n) {
            s1 = rand() % n + 1;
            s2 = rand() % n;
            if (Base[s1 - 1][s2] != '-') {
                while (Base[s1 - 1][s2] != '-') {
                    s1 = rand() % n + 1;
                    s2 = rand() % n;
                }
            }
        }
    }

    else if (1 == Check) {
        s1 = ss1;
        s2 = ss2;
        while (Base[s1 - 1][s2] != '-' && s1 < n + 1 && s1 >= 1) {
            if (c % 2 == 0) {
                s1 = ss1 + q;
                q++;
            }
            else {
                s1 = ss1 - q;
                q++;
            }

        }
        if (s1 >= n + 1 || s1 < 1) {
            q = 0;
            s1 = ss1;
            s2 = ss2;
            while (Base[s1 - 1][s2] != '-' && s1 >= 0 && s1 < n) {
                if (c % 2 == 0) {
                    s1 = ss1 - q;
                    q++;
                }
                else {
                    s1 = ss1 + q;
                    q++;
                }

            }
        }
        if (s1 >= n + 1 || s1 < 1) {
            s1 = rand() % n + 1;
            s2 = rand() % n;
            if (Base[s1 - 1][s2] != '-') {
                while (Base[s1 - 1][s2] != '-') {
                    s1 = rand() % n + 1;
                    s2 = rand() % n;
                }
            }
        }

    }

    else if (2 == Check) {
        s1 = ss1;
        s2 = ss2;
        while (Base[s1 - 1][s2] != '-' && s1 < n + 1 && s1 >= 1 && s2 < n && s2 >= 0) {
            if (c % 2 == 0) {
                s1 = ss1 + q;
                s2 = ss2 - q;
                q++;
            }
            else {
                s1 = ss1 - q;
                s2 = ss2 + q;
                q++;
            }

        }
        if (s1 >= n + 1 || s1 < 1 || s2 >= n || s2 < 0) {
            q = 0;
            s1 = ss1;
            s2 = ss2;
            while (Base[s1 - 1][s2] != '-' && s1 < n + 1 && s1 >= 1 && s2 < n && s2 >= 0) {
                if (c % 2 == 0) {
                    s1 = ss1 - q;
                    s2 = ss2 + q;
                    q++;
                }
                else {
                    s1 = ss1 + q;
                    s2 = ss2 - q;
                    q++;
                }

            }
        }
        if (s1 >= n + 1 || s1 < 1 || s2 >= n || s2 < 0) {
            s1 = rand() % n + 1;
            s2 = rand() % n;
            if (Base[s1 - 1][s2] != '-') {
                while (Base[s1 - 1][s2] != '-') {
                    s1 = rand() % n + 1;
                    s2 = rand() % n;
                }
            }
        }
    }

    else if (3 == Check) {
        s1 = ss1;
        s2 = ss2;
        while (Base[s1 - 1][s2] != '-' && s1 < n + 1 && s1 >= 1 && s2 < n && s2 >= 0) {
            if (c % 2 == 0) {
                s1 = ss1 + q;
                s2 = ss2 + q;
                q++;
            }
            else {
                s1 = ss1 - q;
                s2 = ss2 - q;
                q++;
            }

        }
        if (s1 >= n + 1 || s1 < 1 || s2 >= n || s2 < 0) {
            q = 0;
            s1 = ss1;
            s2 = ss2;
            while (Base[s1 - 1][s2] != '-' && s1 < n + 1 && s1 >= 1 && s2 < n && s2 >= 0) {
                if (c % 2 == 0) {
                    s1 = ss1 - q;
                    s2 = ss2 - q;
                    q++;
                }
                else {
                    s1 = ss1 + q;
                    s2 = ss2 + q;
                    q++;
                }

            }
        }
        if (s1 >= n + 1 || s1 < 1 || s2 >= n || s2 < 0) {
            s1 = rand() % n + 1;
            s2 = rand() % n;
            if (Base[s1 - 1][s2] != '-') {
                while (Base[s1 - 1][s2] != '-') {
                    s1 = rand() % n + 1;
                    s2 = rand() % n;
                }
            }
        }
    }

    else if (4 == Check && t == 'O') {

        s1 = ss1;
        s2 = ss2;
        Check = Check_c(Base, tt, n, s2 + 1, s1, 0,3);
        s1 = Check_f(Base, tt, n, ss1, ss2, Check, c, 1);
        s2 = Check_f(Base, tt, n, ss1, ss2, Check, c, 2);
    }
    else if (4 == Check && t == 'X') {

        s1 = rand() % n + 1;
        s2 = rand() % n;
        if (Base[s1 - 1][s2] != '-') {
            while (Base[s1 - 1][s2] != '-') {
                s1 = rand() % n + 1;
                s2 = rand() % n;
            }
        }
    }
    if (a == 1)
        return s1;
    else
        return s2;

}
void Play_tWF(int n)
{
    int a1 = 1, a2 = 0, Cina1 = 0, c = 0, t = 0, e = 0;
    char Base[20][20], input_t;
    char A1C[21] = "ABCDEFGHIJKLMNOPQRST", A1S[21] = "abcdefghijklmnopqrst";
    char A2C[21], A2S[21];
    strncpy(A2C, A1C, n);
    strncpy(A2S, A1S, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            Base[i][j] = '-';
    Draw_t(Base, n);
    while (true){

        if((c%2==0) &&( t==0))
            cout << "User O: ";
        else if ((c % 2 != 0) && (t == 0))
            cout << "User X: ";
        a1 = 0;
        a2 = 0;
        e = 0;
        cin.ignore();
        cin.get(input_t);
        cin >> Cina1;

        if (Check_i1(Base, input_t, Cina1, n) == 0) {
            t = 1;
            continue;
        }   
        else {
            a1 = Check_i2(Base, input_t, Cina1, n,1);
            a2 = Check_i2(Base, input_t, Cina1, n,2);
        }
 
        if (c % 2 == 0) {
            Base[a1 - 1][a2] = 'O';
            if (1 == Check_v(Base, 'O', n, a2 + 1, a1)) {
                Draw_t(Base, n);
                cout << endl << " ** USER O WON **" << endl;
                break;
            }
        }
        else {
            Base[a1 - 1][a2] = 'X';
            if (1 == Check_v(Base, 'X', n, a2 + 1, a1)) {
                Draw_t(Base, n);
                cout << endl << " ** USER X WON **"<<endl;
                break;
            }
                
        }   


        if (1==Check_e(Base,n))
            break;

        c++;
        t = 0;
        Draw_t(Base, n);
        Draw_g(Base, n);
        input_t = ' ';
    }
}
void Play_tWC1(int n)
{
    int a1 = 1, a2 = 0, Cina1 = 0, t = 0;
    char Base[20][20], input_t;
    char A1C[21] = "ABCDEFGHIJKLMNOPQRST", A1S[21] = "abcdefghijklmnopqrst";
    char A2C[21], A2S[21];
    srand(time(0));
    strncpy(A2C, A1C, n);
    strncpy(A2S, A1S, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            Base[i][j] = '-';
    Draw_t(Base, n);
    while (true) {

        if (t==0)
            cout << "YOU: ";
        a1 = 0;
        a2 = 0;
        cin.ignore();
        cin.get(input_t);
        cin >> Cina1;

        if (Check_i1(Base, input_t, Cina1, n) == 0) {
            t = 1;
            continue;
        }
            
        else {
            a1 = Check_i2(Base, input_t, Cina1, n, 1);
            a2 = Check_i2(Base, input_t, Cina1, n, 2);
        }

        Base[a1 - 1][a2] = 'O';
        if (1 == Check_v(Base, 'O', n, a2 + 1, a1)) {
            Draw_t(Base, n);
            cout << endl << " ** YOU WIN **" << endl;
            break;
        }
        if (1 == Check_e(Base, n))
            break;

        a1 = rand() % n + 1;
        a2 = rand() % n;
        if (Base[a1 - 1][a2] != '-') {
            while (Base[a1 - 1][a2] != '-') {
                a1 = rand() % n + 1;
                a2 = rand() % n;
            }
        }
        cout << "CPU: " << A2C[a2] << a1 << endl;
        Base[a1 - 1][a2] = 'X';
        if (1 == Check_v(Base, 'X', n, a2 + 1, a1)) {
            Draw_t(Base, n);
            cout << endl << " ** YOU LOSE **" << endl;
            break;

        }

        if (1 == Check_e(Base, n))
            break;

        t = 0;
        Draw_t(Base, n);
        Draw_g(Base, n);
        input_t = ' ';
    }
}
void Play_tWC2(int n)
{
    int i = 0, j = 0, a1 = 1, a2 = 0, b[20][20] = { 0 }, b1 = 0, b2 = 0, bs1 = 0, bs2 = 0, Cina1 = 0, c = 0, Check = 0, max1 = 0, max2 = 0 , t = 0;
    char Base[20][20], input_t;
    char A1C[21] = "ABCDEFGHIJKLMNOPQRST", A1S[21] = "abcdefghijklmnopqrst";
    char A2C[21], A2S[21];
    srand(time(0));
    strncpy(A2C, A1C, n);
    strncpy(A2S, A1S, n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            Base[i][j] = '-';
    Draw_t(Base, n);

    //First move
    while (c<1){
        if(t==0)
            cout << "YOU: ";
        a1 = 0;
        a2 = 0;
        cin.ignore();
        cin.get(input_t);
        cin >> Cina1;

        if (Check_i1(Base, input_t, Cina1, n) == 0) {
            t = 1;
            continue;
        }    
        else {
            a1 = Check_i2(Base, input_t, Cina1, n, 1);
            a2 = Check_i2(Base, input_t, Cina1, n, 2);
        }
        Base[a1 - 1][a2] = 'O';

        b1 = rand() % n + 1;
        b2 = rand() % n;
        if (Base[b1 - 1][b2] != '-') {
            while (Base[b1 - 1][b2] != '-') {
                b1 = rand() % n + 1;
                b2 = rand() % n;
            }
        }

        cout << "CPU: " << A2C[b2] << b1 << endl;
        Base[b1 - 1][b2] = 'X';
        Draw_t(Base, n);
        Draw_g(Base, n);
        input_t = ' ';
        c++;

    }
    t = 0;
    c = rand() % 2 + 1;
    //Game
    while (true) {
        if(t == 0)
            cout << "YOU: ";

        cin.ignore();
        cin.get(input_t);
        cin >> Cina1;
        b[b1 - 1][b2] = 1;
        bs1 = b1;
        bs2 = b2;
        b1 = 0;
        b2 = 0;

        if (Check_i1(Base, input_t, Cina1, n) == 0) {
            t = 1;
            continue;
        }
            
        else {
            a1 = Check_i2(Base, input_t, Cina1, n, 1);
            a2 = Check_i2(Base, input_t, Cina1, n, 2);
        }

        Base[a1 - 1][a2] = 'O';
        if (1 == Check_v(Base, 'O', n, a2 + 1, a1)) {
            Draw_t(Base, n);
            cout << endl << " ** YOU WIN **" << endl;
            break;
        }

        if (1 == Check_e(Base, n))
            break;

        max1 = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if ((b[i][j] == 1) && (Check_c(Base, 'X', n, j + 1, i + 1, 1,2) >= max1)) {
                    max1 = Check_c(Base, 'X', n, j + 1, i + 1, 1,2);
                    bs1 = i + 1;
                    bs2 = j;
                }
            }
        }
        max2 = Check_c(Base, 'O', n, a2 + 1, a1, 1,2);
        if (max1 <= max2 || max1 <= 2) {
            Check = Check_c(Base, 'O', n, a2 + 1, a1, 0,2);
            if (0 == Check || 1 == Check || 2 == Check || 3 == Check) {
                b1 = Check_f(Base, 'O', n, a1, a2, Check, c, 1);
                b2 = Check_f(Base, 'O', n, a1, a2, Check, c, 2);
            }
            else if (4 == Check) {
                b1 = Check_f(Base, 'O', n, bs1, bs2, Check, c, 1);
                b2 = Check_f(Base, 'O', n, bs1, bs2, Check, c, 2);
            }
        }
        else {
            b1 = bs1;
            b2 = bs2;
            Check = Check_c(Base, 'X', n, b2 + 1, b1, 0,2);
            b1 = Check_f(Base, 'X', n, bs1, bs2, Check, c, 1);
            b2 = Check_f(Base, 'X', n, bs1, bs2, Check, c, 2);
        }

        if (Base[b1 - 1][b2] != '-') {
            b1 = rand() % n + 1;
            b2 = rand() % n;
            if (Base[b1 - 1][b2] != '-') {
                while (Base[b1 - 1][b2] != '-') {
                    b1 = rand() % n + 1;
                    b2 = rand() % n;
                }
            }
        }

        cout << "CPU: " << A2C[b2] << b1 << endl;
        Base[b1 - 1][b2] = 'X';
        if (1 == Check_v(Base, 'X', n, b2 + 1, b1)) {
            Draw_t(Base, n);
            cout << endl << " ** YOU LOSE **" << endl;
            break;

        }

        if (1 == Check_e(Base, n))
            break;

        Draw_t(Base, n);
        Draw_g(Base, n);
        input_t = ' ';
        c++;
        t = 0;
    }
}
void Play_tWC3(int n)
{
    int i = 0, j = 0, a[20][20] = { 0 }, a1 = 1, a2 = 0, as1 = 0, as2 = 0 , b[20][20] = { 0 }, b1 = 0, b2 = 0, bs1 = 0, bs2 = 0, Cina1 = 0, c = 0, Check = 0, max1 = 0, max2 = 0, t = 0;
    char Base[20][20], input_t;
    char A1C[21] = "ABCDEFGHIJKLMNOPQRST", A1S[21] = "abcdefghijklmnopqrst";
    char A2C[21], A2S[21];
    srand(time(0));
    strncpy(A2C, A1C, n);
    strncpy(A2S, A1S, n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            Base[i][j] = '-';
    Draw_t(Base, n);

    //First move
    while (c < 1) {
        if (t == 0)
            cout << "YOU: ";
        a1 = 0;
        a2 = 0;
        cin.ignore();
        cin.get(input_t);
        cin >> Cina1;

        if (Check_i1(Base, input_t, Cina1, n) == 0) {
            t = 1;
            continue;
        }
        else {
            a1 = Check_i2(Base, input_t, Cina1, n, 1);
            a2 = Check_i2(Base, input_t, Cina1, n, 2);
        }
        Base[a1 - 1][a2] = 'O';

        b1 = rand() % n + 1;
        b2 = rand() % n;
        if (Base[b1 - 1][b2] != '-') {
            while (Base[b1 - 1][b2] != '-') {
                b1 = rand() % n + 1;
                b2 = rand() % n;
            }
        }

        cout << "CPU: " << A2C[b2] << b1 << endl;
        Base[b1 - 1][b2] = 'X';
        Draw_t(Base, n);
        Draw_g(Base, n);
        input_t = ' ';
        c++;
        a[a1 - 1][a2] = 1;

    }
    t = 0;
    c = rand() % 2 + 1;
    //Game
    while (true) {
        if (t == 0)
            cout << "YOU: ";

        cin.ignore();
        cin.get(input_t);
        cin >> Cina1;

        b[b1 - 1][b2] = 1;
        bs1 = b1;
        bs2 = b2;
        b1 = 0;
        b2 = 0;

        if (Check_i1(Base, input_t, Cina1, n) == 0) {
            t = 1;
            continue;
        }
        else {
            a1 = Check_i2(Base, input_t, Cina1, n, 1);
            a2 = Check_i2(Base, input_t, Cina1, n, 2);
            a[a1 - 1][a2] = 1;
            as1 = a1;
            as2 = a2;
        }
        
        Base[a1 - 1][a2] = 'O';
        if (1 == Check_v(Base, 'O', n, a2 + 1, a1)) {
            Draw_t(Base, n);
            cout << endl << " ** YOU WIN **" << endl;
            break;
        }

        if (1 == Check_e(Base, n))
            break;

        max1 = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (a[i][j] == 0 && Check_c(Base, 'X', n, j + 1, i + 1, 1,3) >= max1) {
                    max1 = Check_c(Base, 'X', n, j + 1, i + 1, 1,3);
                    bs1 = i + 1;
                    bs2 = j;
                }
            }
        }
        max2 = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (b[i][j] == 0 && Check_c(Base, 'O', n, j + 1, i + 1, 1,3) >= max2) {
                    max2 = Check_c(Base, 'O', n, j + 1, i + 1, 1,3);
                    as1 = i + 1;
                    as2 = j;
                }
            }
        }

        if (max1 < max2 || max1 <= 2) {
            Check = Check_c(Base, 'O', n, as2 + 1, as1, 0,3);
            if (0 == Check || 1 == Check || 2 == Check || 3 == Check) {
                b1 = Check_f(Base,'O', n, as1, as2, Check, c, 1);
                b2 = Check_f(Base,'O', n, as1, as2, Check, c, 2);  
            }
            else if (4 == Check) {
                b1 = Check_f(Base, 'O', n, bs1, bs2, Check, c, 1);
                b2 = Check_f(Base, 'O', n, bs1, bs2, Check, c, 2);
            }
        }
        else {
            b1 = bs1;
            b2 = bs2;
            Check = Check_c(Base, 'X', n, b2 + 1, b1, 0,3);
            b1 = Check_f(Base, 'X', n, bs1, bs2, Check, c, 1);
            b2 = Check_f(Base, 'X', n, bs1, bs2, Check, c, 2);
        }

        if (Base[b1 - 1][b2] != '-') {
            b1 = rand() % n + 1;
            b2 = rand() % n;
            if (Base[b1 - 1][b2] != '-') {
                while (Base[b1 - 1][b2] != '-') {
                    b1 = rand() % n + 1;
                    b2 = rand() % n;
                }
            }
        }

        cout << "CPU: " << A2C[b2] << b1 << endl;
        Base[b1 - 1][b2] = 'X';
        if (1 == Check_v(Base, 'X', n, b2 + 1, b1)) {
            Draw_t(Base, n);
            cout << endl << " ** YOU LOSE **" << endl;
            break;

        }

        if (1 == Check_e(Base, n))
            break;

        Draw_t(Base, n);
        Draw_g(Base, n);
        input_t = ' ';
        c++;
        t = 0;
    }
}