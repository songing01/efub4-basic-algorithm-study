#include <iostream>
#include <vector>

using namespace std;

int getSolution(int K, vector<vector<int>> arr)
{
    int answer = 1;
    // 금메달 수
    int a = arr[K][0];
    int b = arr[K][1];
    int c = arr[K][2];

    for (int i = 1; i < arr.size(); i++)
    {
        if (i == K)
            continue;

        if (arr[i][0] > a)
        {
            answer++;
        }
        else if (arr[i][0] == a)
        {
            // 은메달
            if (arr[i][1] > b)
            {
                answer++;
            }
            else if (arr[i][1] == b)
            {
                // 동메달
                if (arr[i][2] > c)
                {
                    answer++;
                }
            }
        }
    }

    return answer;
}

int main()
{
    int N, K;
    cin >> N >> K;

    vector<vector<int>> arr(N + 1, vector<int>(3, 0));
    for (int i = 0; i < N; i++)
    {
        int k, a, b, c;
        cin >> k >> a >> b >> c;
        arr[k][0] = a;
        arr[k][1] = b;
        arr[k][2] = c;
    }

    cout << getSolution(K, arr);
}