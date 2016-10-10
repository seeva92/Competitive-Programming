#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct Node
{
    string word;
    Node *next;
};

inline bool is_number(char ch)
{
    return '0' <= ch && ch <= '9';
}

inline bool is_alphabet(char ch)
{
    return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z');
}

int main()
{
    Node *head = NULL;

    string word;
    char ch;

    ch = getchar();
    while (true)
    {
        if (is_number(ch))
        {
            if (ch == '0') break;
            int num = 0;
            while (is_number(ch))
            {
                num = num * 10 + (ch - '0');
                ch = getchar();
            }
            Node *now = head, *prev = NULL;
            for (int i = 1; i < num ; i ++)
            {
                prev = now;
                now = now->next;
            }
            cout << now->word;
            if (now != head)
            {
                prev->next = now->next;
                now->next = head;
                head = now;
            }
        }
        else if (is_alphabet(ch))
        {
            string word;
            while (is_alphabet(ch))
            {
                word += ch;
                ch = getchar();
            }
            cout << word;
            Node *n = new Node;
            n->word = word;
            n->next = head;
            head = n;
        }
        else
        {
            putchar(ch);
            ch = getchar();
        }
    }
    return 0;
}