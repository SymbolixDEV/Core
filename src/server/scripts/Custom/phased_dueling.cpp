#include "MapManager.h"
 
class PhasedDueling : public PlayerScript
{
public:
        PhasedDueling() : PlayerScript("PhasedDueling") { }
 
        void OnDuelStart(Player* firstplayer, Player* secondplayer)
        {
                uint32 PlayersInsidePhase = 0;
                uint32 PhaseToCheck = 1;
                Map* map = sMapMgr->FindMap(firstplayer->GetMapId(), firstplayer->GetInstanceId());
 
                if (!map)
                        return;
                Map::PlayerList const& players = map->GetPlayers();
                for (Map::PlayerList::const_iterator iter = players.begin(); iter != players.end(); ++iter)
                {
                        Player* check = iter->GetSource();
                        if (!check || !check->GetSession())
                                continue;
 
                        if (check->GetPhaseMask() == PhaseToCheck)
                        {
                                ++PlayersInsidePhase;
                                ++PhaseToCheck;
                                PlayersInsidePhase = 0;
                        }
                }
 
                if (PlayersInsidePhase == 0)
                {
                        firstplayer->SetPhaseMask(PhaseToCheck, true);
                        secondplayer->SetPhaseMask(PhaseToCheck, true);
                }
		}
};
 
void AddSC_PhasedDueling()
{
        new PhasedDueling();
}