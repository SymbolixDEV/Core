/*
<--------------------------------------------------------------------------->
- Made by: ??
- Developer(s): Ghostcrawler336
- Complete: %100
- ScriptName: 'Lotto system'
- Comment: N/A
<--------------------------------------------------------------------------->
*/
#include "ScriptPCH.h"

enum eEnums
{
	ITEM_LOTTO   = 29434,
	
};

class npc_lotto : public CreatureScript
{
    public:
        npc_lotto() : CreatureScript("npc_lotto") { }

        bool OnGossipHello(Player* player, Creature* creature)
        {
			if (player->HasItemCount(ITEM_LOTTO, 1, false))
			{
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Test your luck in the lottery this week.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
			}
			else
				 ChatHandler(player->GetSession()).PSendSysMessage("You don't have enough Lottery Tickets");

			player->PlayerTalkClass->SendGossipMenu(65002, creature->GetGUID());
            return true;
		}

		bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
		{
			
            player->PlayerTalkClass->ClearMenus();
            player->CLOSE_GOSSIP_MENU();
        switch (action)
            {
		    case GOSSIP_ACTION_INFO_DEF+1:
			    ChatHandler(player->GetSession()).PSendSysMessage("Greetings competitor! Thank you for purchasing your Lottery ticket, we give out prizes every Monday. Prizes change every week!", player->GetGUID());
				WorldDatabase.PExecute("INSERT INTO game_lotto (entry, comment) values ('%s',0)", player->GetName().c_str());
				player->DestroyItemCount(ITEM_LOTTO, 1, true, false);
				break;
		    }

			player->CLOSE_GOSSIP_MENU();
			return true;
	    }


};

void AddSC_npc_lotto()
{
	new npc_lotto();
}