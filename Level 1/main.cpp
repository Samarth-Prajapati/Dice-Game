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
    Player(string name)
    {
        this->name = name;
        this->score = 5;
    }
};

class Bot
{
public:
    int score;
    Bot()
    {
        this->score = 5;
    }
};

class Game
{
public:
    void vsBot(string player1, string player2, Player &p1, Bot &b, mt19937 &gen)
    {
        uniform_int_distribution<int> dis(1, 6);
        cout << player1 << " vs " << player2 << endl;

        while (true)
        {
            cout << "Press 'Enter' to roll dice : ";
            cin.get();
            int r1 = dis(gen);
            int r2 = dis(gen);
            cout << player1 << " rolled : " << r1 << endl;
            cout << player2 << " rolled : " << r2 << endl;

            if (r1 > r2)
            {
                b.score--;
                cout << player2 << " lost 1 point" << endl;
            }
            else if (r1 < r2)
            {
                p1.score--;
                cout << player1 << " lost 1 point" << endl;
            }
            else
            {
                cout << "It's a tie" << endl;
            }

            if (p1.score == 0 || b.score == 0)
            {
                cout << "Game Over" << endl;
                break;
            }
        }
    }

    void vsPlayer(string player1, string player2, Player &p1, Player &p2, mt19937 &gen)
    {
        uniform_int_distribution<int> dis(1, 6);
        cout << player1 << " vs " << player2 << endl;

        while (true)
        {
            cout << player1 << " press 'Enter' to roll dice : ";
            cin.get();
            int r1 = dis(gen);
            cout << player2 << " press 'Enter' to roll dice : ";
            cin.get();
            int r2 = dis(gen);

            cout << player1 << " rolled : " << r1 << endl;
            cout << player2 << " rolled : " << r2 << endl;

            if (r1 > r2)
            {
                p2.score--;
                cout << player2 << " lost 1 point" << endl;
            }
            else if (r1 < r2)
            {
                p1.score--;
                cout << player1 << " lost 1 point" << endl;
            }
            else
            {
                cout << "It's a tie" << endl;
            }

            if (p1.score == 0 || p2.score == 0)
            {
                cout << "Game Over" << endl;
                break;
            }
        }
    }

    void result(string player1, string player2, int score1, int score2)
    {
        cout << "-------------------------------------" << endl;
        if (score1 == 0)
        {
            cout << player2 << " Won !! " << endl;
        }
        else
        {
            cout << player1 << " Won !! " << endl;
        }
    }
};

int main()
{
    Game g;
    mt19937 gen(static_cast<unsigned>(time(0))); // Initialize random number generator

    string choice, player1, player2;
    cout << "----------LEVEL 1 DICE GAME----------" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Rules : " << endl;
    cout << "1. Each player will start with 5 points ." << endl;
    cout << "2. Each player will roll the dice and the losing player will lose 1 point." << endl;
    cout << "3. The game will continue until one of the player's score reaches 0." << endl;
    cout << "4. The player with score 0 will lose the game." << endl;
    cout << "-------------------------------------" << endl;
    cout << "Want to play against Bot or Player? (Bot/Player): ";
    cin >> choice;
    for (char &c : choice)
    {
        c = tolower(c);
    }

    cout << "Enter Player 1 name : ";
    cin >> player1;
    cin.ignore();
    Player p1(player1);

    if (choice == "bot")
    {
        Bot b;
        g.vsBot(player1, "Bot", p1, b, gen);
        g.result(player1, "Bot", p1.score, b.score);
    }
    else if (choice == "player")
    {
        cout << "Enter Player 2 name : ";
        cin >> player2;
        cin.ignore();
        Player p2(player2);
        g.vsPlayer(player1, player2, p1, p2, gen);
        g.result(player1, player2, p1.score, p2.score);
    }
    else
    {
        cout << "Invalid choice" << endl;
        return 0;
    }

    cout << "-------------------------------------" << endl;
    return 0;
}
