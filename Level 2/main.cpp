#include <iostream>
#include <string>
#include <random>
#include <ctime>
using namespace std;

class Player
{
public:
    string name;
    int score;
    Player(string name) : name(name), score(0) {}
};

class Bot
{
public:
    int score;
    Bot() : score(0) {}
};

class Game
{
public:
    void vsBot(Player &p1, Bot &b, int rounds)
    {
        int r1, r2;
        mt19937 gen(static_cast<unsigned>(time(0)));
        uniform_int_distribution<int> dis(1, 6);

        cout << p1.name << " vs Bot" << endl;
        for (int i = 0; i < rounds; i++)
        {
            cout << "Press 'Enter' to roll dice: ";
            cin.get();
            r1 = dis(gen);
            r2 = dis(gen);
            cout << p1.name << " rolled: " << r1 << endl;
            cout << "Bot rolled: " << r2 << endl;

            if (r1 > r2)
                p1.score++;
            else if (r1 < r2)
                b.score++;
            else
            {
                p1.score++;
                b.score++;
                cout << "It's a tie!" << endl;
            }
        }
        result(p1.name, "Bot", p1.score, b.score);
    }

    void vsPlayer(Player &p1, Player &p2, int rounds)
    {
        int r1, r2;
        mt19937 gen(static_cast<unsigned>(time(0)));
        uniform_int_distribution<int> dis(1, 6);

        cout << p1.name << " vs " << p2.name << endl;
        for (int i = 0; i < rounds; i++)
        {
            cout << p1.name << " press 'Enter' to roll dice: ";
            cin.get();
            r1 = dis(gen);
            cout << p2.name << " press 'Enter' to roll dice: ";
            cin.get();
            r2 = dis(gen);

            cout << p1.name << " rolled: " << r1 << endl;
            cout << p2.name << " rolled: " << r2 << endl;

            if (r1 > r2)
                p1.score++;
            else if (r1 < r2)
                p2.score++;
            else
            {
                p1.score++;
                p2.score++;
                cout << "It's a tie!" << endl;
            }
        }
        result(p1.name, p2.name, p1.score, p2.score);
    }

    void result(string player1, string player2, int score1, int score2)
    {
        cout << "-------------------------------------" << endl;
        if (score1 > score2)
            cout << player1 << " Won the match with " << score1 << " points!" << endl;
        else if (score1 < score2)
            cout << player2 << " Won the match with " << score2 << " points!" << endl;
        else
            cout << "Match is a tie!" << endl;
    }
};

int main()
{
    Game g;
    string choice, player1, player2;
    int rounds;

    cout << "----------LEVEL 2 DICE GAME----------" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Rules: " << endl;
    cout << "1. Player will decide whether to play against bot or another player." << endl;
    cout << "2. Player will decide the number of rounds." << endl;
    cout << "3. After the last round, the player with the highest points wins the match." << endl;
    cout << "-------------------------------------" << endl;
    cout << "Enter Number of Rounds: ";
    cin >> rounds;
    cout << "Want to play against Bot or Player? (Bot/Player): ";
    cin >> choice;
    for (char &c : choice)
    {
        c = tolower(c);
    }
    cout << "Enter Player 1 name: ";
    cin >> player1;
    cin.ignore();
    Player p1(player1);

    if (choice == "bot")
    {
        Bot b;
        g.vsBot(p1, b, rounds);
    }
    else if (choice == "player")
    {
        cout << "Enter Player 2 name: ";
        cin >> player2;
        cin.ignore();
        Player p2(player2);
        g.vsPlayer(p1, p2, rounds);
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }
    cout << "-------------------------------------" << endl;
    return 0;
}
