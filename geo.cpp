#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int K = 20;
    float p = 1.0 / 6;
    int f[K] = {0};

    srand(time(0));

    // ������ ���� �� �ݺ�
    for (int e = 0; e < 10000; ++e) {
        int count = 0;
        for (int k = 1; k<=K;++k) {
            count++;
            if ((rand() % 6) + 1 == 6)break;
        }
        
        if (count <= K) f[count-1]++; // �󵵼� ������Ʈ
    }

    // �̷��� Ȯ���� ������ Ȯ�� ���
    cout << "k\t�̷�\t����" << endl;
    for (int k = 1; k <= K; ++k) {
        float th = pow(1 - p, k - 1) * p;
        float ex = static_cast<float>(f[k - 1]) / 10000;
        cout << k << "\t" << th << "\t\t" << ex << endl;
    }

    return 0;
}
