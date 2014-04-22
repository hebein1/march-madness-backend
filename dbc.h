#ifndef DBC_H 
#define DBC_H

#include <list>
#include <string>
#include <sqlite3.h>

struct Game {
    std::string homeTeam;
    std::string awayTeam;

    float homeWL, homePoints, homefgm, homefga, homefgPer, hometwoMade, hometwoAtt, hometwoPer, homethreeMade, homethreeAtt, homethreePer, homeftm, homefta, homeftPer, homeoffReb, homedefReb, hometotalReb, homepps, homeadjFG, homeassist, hometo, homeapto, homesteals, homefouls, homestealPerTO, homestealPerFoul, homeblocks, homeblocksPerFoul;
    float awayWL, awaypoints, awayfgm, awayfga, awayfgPer, awaytwoMade, awaytwoAtt, awaytwoPer, awaythreeMade, awaythreeAtt, awaythreePer, awayftm, awayfta, awayftPer, awayoffReb, awaydefReb, awaytotalReb, awaypps, awayadjFG, awayassist, awayto, awayapto, awaysteals, awayfouls, awaystealPerTO, awaystealPerFoul, awayblocks, awayblocksPerFoul;  

    Game(std::string homeTeam, std::string awayTeam, float homeWL, float homePoints, float homefgm, float homefga, float homefgPer, float hometwoMade, float hometwoAtt, float hometwoPer, float homethreeMade, float homethreeAtt, float homethreePer, float homeftm, float homefta, float homeftPer, float homeoffReb, float homedefReb, float hometotalReb, float homepps, float homeadjFG, float homeassist, float hometo, float homeapto, float homesteals, float homefouls, float homestealPerTO, float homestealPerFoul, float homeblocks, float homeblocksPerFoul, float awayWL, float awaypoints, float awayfgm, float awayfga, float awayfgPer, float awaytwoMade, float awaytwoAtt, float awaytwoPer, float awaythreeMade, float awaythreeAtt, float awaythreePer, float awayftm, float awayfta, float awayftPer, float awayoffReb, float awaydefReb, float awaytotalReb, float awaypps, float awayadjFG, float awayassist, float awayto, float awayapto, float awaysteals, float awayfouls, float awaystealPerTO, float awaystealPerFoul, float awayblocks, float awayblocksPerFoul)  :
    homeTeam(homeTeam), awayTeam(awayTeam), homeWL(homeWL), homePoints(homePoints), homefgm(homefgm), homefga(homefga), homefgPer(homefgPer), hometwoMade(hometwoMade), hometwoAtt(hometwoAtt), hometwoPer(hometwoPer), homethreeMade(homethreeMade), homethreeAtt(homethreeAtt), homethreePer(homethreePer), homeftm(homeftm), homefta(homefta), homeftPer(homeftPer), homeoffReb(homeoffReb), homedefReb(homedefReb), hometotalReb(hometotalReb), homepps(homepps), homeadjFG(homeadjFG), homeassist(homeassist), hometo(hometo), homeapto(homeapto), homesteals(homesteals), homefouls(homefouls), homestealPerTO(homestealPerTO), homestealPerFoul(homestealPerFoul), homeblocks(homeblocks), homeblocksPerFoul(homeblocksPerFoul), awayWL(awayWL), awaypoints(awaypoints), awayfgm(awayfgm), awayfga(awayfga), awayfgPer(awayfgPer), awaytwoMade(awaytwoMade), awaytwoAtt(awaytwoAtt), awaytwoPer(awaytwoPer), awaythreeMade(awaythreeMade), awaythreeAtt(awaythreeAtt), awaythreePer(awaythreePer), awayftm(awayftm), awayfta(awayfta), awayftPer(awayftPer), awayoffReb(awayoffReb), awaydefReb(awaydefReb), awaytotalReb(awaytotalReb), awaypps(awaypps), awayadjFG(awayadjFG), awayassist(awayassist), awayto(awayto), awayapto(awayapto), awaysteals(awaysteals), awayfouls(awayfouls), awaystealPerTO(awaystealPerTO), awaystealPerFoul(awaystealPerFoul), awayblocks(awayblocks), awayblocksPerFoul(awayblocksPerFoul) {}

};

struct Team {
    std::string name;

    float wl, fgm, fga, fgPer, twoMade, twoAtt, twoPer, threeMade, threeAtt, threePer, ftm, fta, ftPer, offReb, defReb, totalReb, pps, adjFG, assist, to, apto, steals, fouls, stealPerTO, stealPerFoul, blocks, blocksPerFoul; 

    Team(std::string name, float wl, float fgm, float fga, float fgPer, float twoMade, float twoAtt, float twoPer, float threeMade, float threeAtt, float threePer, float ftm, float fta, float ftPer, float offReb, float defReb, float totalReb, float pps, float adjFG, float assist, float to, float apto, float steals, float fouls, float stealPerTO, float stealPerFoul, float blocks, float blocksPerFoul) :
    name(name), wl(wl), fgm(fgm), fga(fga), fgPer(fgPer), twoMade(twoMade), twoAtt(twoAtt), twoPer(twoPer), threeMade(threeMade), threeAtt(threeAtt), threePer(threePer), ftm(ftm), fta(fta), ftPer(ftPer), offReb(offReb), defReb(defReb), totalReb(totalReb), pps(pps), adjFG(adjFG), assist(assist), to(to), apto(apto), steals(steals), fouls(fouls), stealPerTO(stealPerTO), stealPerFoul(stealPerFoul), blocks(blocks), blocksPerFoul(blocksPerFoul) {}

};

class DBC{
    public:
        DBC();
        DBC(std::string dbfile);
        ~DBC();
        std::list<Game> retrieveGames();
        std::list<Team> retrieveTeams();

        void writeC5(std::string filename);
        void writeANN(std::string filename);
        void writeC5Teams(std::string filename);
        void writeANNTeams(std::string filename);
   private:
        sqlite3 * db;
};


#endif
