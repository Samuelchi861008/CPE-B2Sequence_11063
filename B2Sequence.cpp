/* **************************************************************************

    * File Name : B2Sequence.cpp

    * Creation Date : 2018-09-14 15:13:33

    * Last Modified : 2018-09-29 16:01:40

    * Created By : Samuel Chi <Yu-Ning Chi>

************************************************************************** */

#include <iostream>
using namespace std;

int main()
{
    int numOfInput; //欲輸入的資料個數
    int inputAry[100000]; //輸入資料儲存陣列
    int checkAry[200000]; //結果檢查
    int isB2; //是否為B2-Sequence
    int numOfCase = 0; //資料組數
    
    while(cin >> numOfInput) //輸入個數
    {
        numOfCase++; //組數加1
        isB2 = 1; //預設為是B2
        for(int l = 0; l < 200000; l++)
            checkAry[l] = 0; //初始化checkAry
        for(int i = 0; i < 100000; i++)
            inputAry[i] = 0; //初始化inputAry
        for(int j = 0; j < numOfInput; j++)
            cin >> inputAry[j]; //輸入資料
        for(int k = 0; k < numOfInput; k++)
            for(int h = k; h < numOfInput; h++)
                if(inputAry[k] > inputAry[h] || 
                    checkAry[inputAry[k] + inputAry[h]] != 0)
                { //只要前數大於後數，或兩兩相加之數早已存在
                    isB2 = 0;
                    break;
                }
                else //若不存在則將checkAry 設定存在
                    checkAry[inputAry[k] + inputAry[h]] = 1;
        cout << "Case #" << numOfCase << ": ";
        if(isB2 == 1)
            cout << "It is a B2-Sequence.\n" << endl;
        else
            cout << "It is not a B2-Sequence.\n" << endl;
    }
    return 0;
}
