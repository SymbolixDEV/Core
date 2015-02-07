#include "ScriptPCH.h"
using namespace std;

class npc_arena_teamTop : public CreatureScript
{
   public:
	   npc_arena_teamTop() : CreatureScript("npc_arena_teamTop") { }

	   bool OnGossipHello(Player * player, Creature * creature)
	   {
		   player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Achievement_Arena_2v2_7:30|t View top 2v2 Arena Teams", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
		   player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Achievement_Arena_3v3_5:30|t View top 3v3 Arena Teams", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
		   player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Nevermind", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
		   player->SEND_GOSSIP_MENU(1, creature->GetGUID());
		   return true;
	   }

	   bool OnGossipSelect(Player * player, Creature * creature, uint32 sender, uint32 actions)
	   {
		   if(sender == GOSSIP_SENDER_MAIN)
		   {
			   switch(actions)
			   {
			       case GOSSIP_ACTION_INFO_DEF+1:
				   {
					   QueryResult result = CharacterDatabase.Query("SELECT name,rating FROM arena_team WHERE type='2' ORDER BY rating DESC LIMIT 10");
					   if(!result)
						   return false;

					   Field * fields = NULL;
					   player->MonsterWhisper("|cff4169E1Here are the top 10 2v2 arena teams:|r", player->GetGUID());
					   do
					   {
						   fields = result->Fetch();
						   string arena_name = fields[0].GetString();
						   uint32 rating = fields[1].GetUInt32();
						   char msg[250];
						   snprintf(msg, 250, "Team Name: |cffFFFF00%s|r, Team Rating: %u \n", arena_name.c_str(), rating);
						   player->MonsterWhisper(msg, player->GetGUID());
					   }while(result->NextRow());
				   }break;

			       case GOSSIP_ACTION_INFO_DEF+2:
				   {
					   QueryResult result = CharacterDatabase.Query("SELECT name,rating FROM arena_team WHERE type='3' ORDER BY rating DESC LIMIT 10");
					   if(!result)
						   return false;

					   Field * fields = NULL;
					   player->MonsterWhisper("|cff4169E1Here are the top 10 3v3 arena teams:|r", player->GetGUID());
					   do
					   {
						   fields = result->Fetch();
						   string arena_name = fields[0].GetString();
						   uint32 rating = fields[1].GetUInt32();
						   char msg[250];
						   snprintf(msg, 250, "Team Name: |cffFFFF00%s|r, Team Rating: %u \n", arena_name.c_str(), rating);
						   player->MonsterWhisper(msg, player->GetGUID());
					   }while(result->NextRow());
				   }break;

			       case GOSSIP_ACTION_INFO_DEF+3:
					   {
						   player->PlayerTalkClass->SendCloseGossip();
					   }break;
			   }
		   }

		   return true;
	   }
};

void AddSC_npc_arena_setup()
{
	new npc_arena_teamTop;
}