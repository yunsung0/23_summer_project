#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

struct Word {
    char korean[50];
    char english[50];
    char hint[50];
};

int main() {
    printf("\n# English word guessing program #\n");
    printf("(If you want a hint, type 'hint')\n\n");

    struct Word words[] = {
        { "����, ����; ����", "approval", "starting with 'a', 8 letters" },
        { "����; �����ϴ�; �����ϴ�", "bear", "starting with 'b', 4 letters" },
        { "�������; ����", "captive", "starting with 'c', 7 letters" },
        { "����", "disclosure", "starting with 'd', 10 letters" },
        { "������; ����ϴ� ��", "equivalent", "starting with 'e', 10 letters" },
        { "�����ϰ� �ϴ�", "facilitate", "starting with 'f', 10 letters" },
        { "����; ������ϴ�", "grudge", "starting with 'g', 6 letters" },
        { "�����ϴ�", "hinder", "starting with 'h', 6 letters" },
        { "�����ϴ�; �ΰ��ϴ�", "impose", "starting with 'i', 6 letters" },
        { "���ǲ�� ���̴�", "loom", "starting with 'l', 4 letters" },
        { "�պ��ϴ�", "m", "starting with 'merge', 5 letters" },
        { "������", "permeate", "starting with 'p', 8 letters" },
        { "�����ϴ�; ������", "renounce", "starting with 'r', 8 letters" },
        { "����, ���", "solidarity", "starting with 's', 10 letters" },
        { "�ǽ��� ��������", "unquestionable", "starting with 'u', 14 letters" },
        { "�����ϴ�", "validate", "starting with 'v', 8 letters" },
        { "��������; öȸ�ϴ�; Ż���ϴ�", "withdraw", "starting with 'withdraw', 8 letters" },
        // �ܾ�, ��, ��Ʈ �ʿ��� ������ŭ �߰� ����
    };

    int totalWords = sizeof(words) / sizeof(words[0]);
    int randomIndex;
    char guess[50];
    int correctCount = 0;
    int incorrectCount = 0;

    srand(time(0));

    while (correctCount + incorrectCount < totalWords) {
        // ���� �������� ���� �ܾ� �� �������� ����
        do {
            randomIndex = rand() % totalWords;
        } while (words[randomIndex].english[0] == '\0'); // �̹� ������ �ܾ��� ��� �ٽ� ����

        printf("%s\n", words[randomIndex].korean);
        scanf("%s", guess);

        // ��Ʈ�� ���ϴ� ��� ��Ʈ ����, �̾ ���� Ǯ��
        if (strcmp(guess, "hint") == 0) {
            printf("%s\n\n", words[randomIndex].hint);
            printf("%s\n", words[randomIndex].korean);
            scanf("%s", guess);
        }

        // ������ ���Ͽ� ���� ���θ� �Ǵ��ϰ� ��� ����
        if (strcmp(guess, words[randomIndex].english) == 0) {
            printf("Correct!\n\n");
            correctCount++;
        }
        else {
            printf("Incorrect. The answer is %s.\n\n", words[randomIndex].english);
            incorrectCount++;
        }

        // �̹� ������ �ܾ�� ǥ���Ͽ� �ߺ� ���� ����
        words[randomIndex].english[0] = '\0';
    }

    // ��� �ܾ �� ������ �� �ǵ�� ����
    printf("*** RESULT ***\n");
    printf("Number of correct words: %d\n", correctCount);
    printf("Number of incorrect words: %d\n", incorrectCount);
    printf("Accuracy: %.2f%%\n\n", (float)correctCount / totalWords * 100);

    // �ٽ� �õ� ���θ� ���� �޽��� ���
    char tryAgain;
    printf("You've completed all the words. Do you wanna try again? (y/n): ");
    scanf(" %c", &tryAgain);

    if (tryAgain == 'y' || tryAgain == 'Y') {
        // ����ڰ� �ٽ� �õ��ϴ� ��� - ������ �ܾ �ʱ�ȭ�ϰ� ���� �����
        for (int i = 0; i < totalWords; i++) {
            words[i].english[0] = words[i].korean[0]; // �������� ���� ���� �ܾ �ٽ� �ʱ�ȭ
        }
        correctCount = 0;
        incorrectCount = 0;
        main(); // �Լ��� ��ȣ���Ͽ� ���� �����
    }
    else {
        // ����ڰ� ��õ����� �ʴ� ��� - ���α׷� ����
        printf("Thank you for playing!\n");
    }
    return 0;
}
