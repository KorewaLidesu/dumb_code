#include <iostream>

class SoccerPlayer
{
    friend SoccerPlayer operator+(SoccerPlayer, SoccerPlayer);
    friend SoccerPlayer operator-(SoccerPlayer, SoccerPlayer);
    friend bool operator>(SoccerPlayer, SoccerPlayer);
    private:
        int jerseyNum;
        int goals;
        int assists;
    public:
        SoccerPlayer(int num = 9999, int goals = 0, int assists = 0) 
            : jerseyNum(num), goals(goals), assists(assists) {}
        int getJerseyNum(void) { return jerseyNum; }
        int getGoals(void) { return goals; }
        int getAssists(void) { return assists; }
};

SoccerPlayer operator+(SoccerPlayer base, SoccerPlayer add)
{
    return SoccerPlayer(base.getJerseyNum(), base.goals + add.goals, base.assists + add.assists);
}

SoccerPlayer operator-(SoccerPlayer base, SoccerPlayer sub)
{
    return SoccerPlayer(base.getJerseyNum(), base.goals - sub.goals, base.assists - sub.assists);
}

bool operator>(SoccerPlayer player1, SoccerPlayer player2)
{
    // Check total of goals and assists
    return player1.goals + player1.assists > player2.goals + player2.assists;
}

int main()
{
    // Initial SoccerPlayer
    int initial = 11;
    SoccerPlayer player[initial];
    std::cout << "Nums of initial SoccerPlayer: " << initial << std::endl
        << "Start initial phase for SoccerPlayer" << std::endl;
    for (int i = 0 ; i < initial ; i++)
    {
        int jerseyNum, goals, assists;
        std::cout << "Soccer Player #" << i + 1 << std::endl
            << "Jersey Number: "; std::cin >> jerseyNum;
        std::cout << "Goals: "; std::cin >> goals;
        std::cout << "Assists: "; std::cin >> assists;
        std::cout << "============================" << std::endl;
        player[i] = SoccerPlayer(jerseyNum, goals, assists);
    }

    // Guess the greatest player was the first one
    SoccerPlayer greatestPlayer = player[0];

    // Find the player who has the greatest total of goals plus assists.
    for (int i = 1 ; i < initial ; i++)
    {
        if (player[i] > greatestPlayer)
        {
            greatestPlayer = SoccerPlayer(player[i].getJerseyNum(), 
                player[i].getGoals(), player[i].getAssists());
        }
    }

    // Output the info about greatest player
    std::cout << "The greatest player:" << std::endl
        << "Jersey Number: " << greatestPlayer.getJerseyNum() << std::endl
        << "Goals: " << greatestPlayer.getGoals() << std::endl
        << "Assists: " << greatestPlayer.getAssists() << std::endl;
}