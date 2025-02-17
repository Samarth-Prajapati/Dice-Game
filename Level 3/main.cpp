#include <iostream>
#include <map>
#include <algorithm>
#include <random>
#include <ctime>
#include <vector>
using namespace std;
class Player
{
public:
    string name;
    int score;
    Player() {};
    Player(string name, int score = 0)
    {
        this->name = name;
        this->score = score;
    }
};
class Game
{
private:
    string playerName;
    map<int, Player> players;

public:
    Game() {};
    void playerDetails(int totalPlayers);
    void displayPlayers();
    void playGame(int rounds, int totalPlayers);
    void displayWinner();
    void displayScoreboard();
};
int main()
{
    int totalPlayers, rounds;
    Game g;
    cout << "----------LEVEL 3 DICE GAME----------" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Rules - " << endl;
    cout << " 1. Enter number of players ." << endl;
    cout << " 2. Enter names of each player , if not enter Bot for computer to play against you ." << endl;
    cout << " 3. Enter number of rounds ." << endl;
    cout << " 4. Play all the rounds and at the end of the game winner will we declared with maximum score ." << endl;
    cout << "-------------------------------------" << endl;
    cout << "Enter number of players : " << endl;
    cin >> totalPlayers;
    g.playerDetails(totalPlayers);
    g.displayPlayers();
    cout << "Enter number of rounds : " << endl;
    cin >> rounds;
    g.playGame(rounds, totalPlayers);
    g.displayWinner();
    g.displayScoreboard();
    cout << "Thank you for playing the game ." << endl;
    cout << "-------------------------------------" << endl;
    return 0;
}
void Game::playerDetails(int totalPlayers)
{
    cin.ignore();
    for (int i = 1; i <= totalPlayers; i++)
    {
        cout << "Enter name of player ( if bot say 'Bot' ) : " << endl;
        getline(cin, playerName);
        string name = playerName;
        for (char &c : name)
        {
            c = tolower(c);
        }
        if (name == "bot")
        {
            players[i] = Player("Bot");
            cout << players[i].name << " added successfully ." << endl;
        }
        else
        {
            players[i] = Player(playerName);
            cout << playerName << " player added successfully ." << endl;
        }
        cout << "-------------------------------------" << endl;
    }
}
void Game::displayPlayers()
{
    for (auto &player : players)
    {
        cout << "Player " << player.first
             << " | Name: " << player.second.name
             << " | Score: " << player.second.score
             << endl;
    }
    cout << "-------------------------------------" << endl;
}
void Game::playGame(int rounds, int totalPlayers)
{
    cout << "\n-------------------------------------" << endl;
    int roll;
    mt19937 gen(time(0));
    uniform_int_distribution<int> dist(1, 6);
    cin.ignore();
    for (int i = 1; i <= rounds; i++)
    {
        cout << "Round " << i << " : " << endl;
        for (int i = 1; i <= totalPlayers; i++)
        {
            if (players[i].name == "Bot")
            {
                cout << "Bot's turn : " << endl;
                roll = dist(gen);
                cout << "Bot rolled : " << roll << endl;
                players[i].score += roll;
                cout << "Bot's score : " << players[i].score << endl;
                cout << "\n-------------------------------------" << endl;
            }
            else
            {
                cout << players[i].name << "'s turn : " << endl;
                cout << "Press any key to roll the dice : " << endl;
                cin.ignore();
                roll = dist(gen);
                cout << "You rolled : " << roll << endl;
                players[i].score += roll;
                cout << players[i].name << "'s score : " << players[i].score << endl;
                cout << "\n-------------------------------------" << endl;
            }
        }
    }
}
void Game::displayWinner()
{
    vector<pair<int, Player>> sortedPlayers(players.begin(), players.end());
    sort(sortedPlayers.begin(), sortedPlayers.end(),
         [](const pair<int, Player> &a, const pair<int, Player> &b)
         {
             return a.second.score > b.second.score;
         });
    cout << "Winner of the game is : " << sortedPlayers[0].second.name << " with score : " << sortedPlayers[0].second.score << endl;
}
void Game::displayScoreboard()
{
    cout << "Scoreboard : " << endl;
    cout << "-------------------------------------" << endl;
    vector<pair<int, Player>> sortedPlayers(players.begin(), players.end());
    sort(sortedPlayers.begin(), sortedPlayers.end(),
         [](const pair<int, Player> &a, const pair<int, Player> &b)
         {
             return a.second.score > b.second.score;
         });
    for (const auto &player : sortedPlayers)
    {
        cout << "Player " << player.first
             << " | Name: " << player.second.name
             << " | Score: " << player.second.score
             << endl;
    }
    cout << "-------------------------------------" << endl;
}