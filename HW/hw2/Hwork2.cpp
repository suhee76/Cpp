#include <iostream>
#include <string>
#include <random>

using namespace std;

class Player {
public:
    string name;
    Player();
    ~Player() { }
};

Player::Player() {
    name = "";
}

class GamblingGame {
public:
    GamblingGame(Player& p1, Player& p2);
};

GamblingGame::GamblingGame(Player& p1, Player& p2) {
    cout << p1.name << ":<Enter>";
    cin.get(); // ����� �Է� ���

    random_device rd;  // �õ� ������ ���� ���� ��ġ
    mt19937 gen(rd()); // Mersenne Twister ����
    uniform_int_distribution<int> dis(0, 2); // 0~2 ������ ���� ����

    // ù ��° �÷��̾��� ��
    while (true) {
        int num[3];
        for (int i = 0; i < 3; i++) {
            num[i] = dis(gen); // 0~2���� ���� ���� ����
        }

        cout << "\t\t" << num[0] << "\t" << num[1] << "\t" << num[2] << "\t";

        // �¸� ���� üũ
        if (num[0] == num[1] && num[0] == num[2]) {
            cout << p1.name << "�� �¸�!!" << endl;
            break;
        }
        else {
            cout << "�ƽ�����!" << endl;

            // ���� �ٲٱ� ���� �̸��� ������Ʈ
            swap(p1, p2); // �� �÷��̾��� ���� �ٲ�
            cout << p1.name << ":<Enter>"; // ���� �÷��̾��� �� �ȳ�
            cin.get(); // ����� �Է� ���
        }
    }
}

int main() {
    Player* player = new Player[2];
    cout << "***** ���� ������ �����մϴ�. *****" << endl;

    cout << "ù��° ���� �̸�>>";
    getline(cin, player[0].name, '\n');
    cout << "�ι�° ���� �̸�>>";
    getline(cin, player[1].name, '\n');

    GamblingGame game(player[0], player[1]);

    delete[] player; // ��ü �迭 �Ҹ�
}
