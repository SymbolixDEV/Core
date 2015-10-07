/*
Made by: SymbolixDEV
Created for: http://curseofdoom.eu
Realm: Tournament
Complete Status: 100%
Bugs: None
*/

#include "ScriptPCH.h"

class Mall_GuideA : public CreatureScript
{
public:
	Mall_GuideA() : CreatureScript("Mall_GuideA"){}

	bool OnGossipHello(Player* player, Creature* creature)
	{
		{
		player->ADD_GOSSIP_ITEM(9, "|TInterface/ICONS/INV_Misc_Coin_01:30|t  Mall Guide / Places", GOSSIP_SENDER_MAIN, 1);
		player->ADD_GOSSIP_ITEM(9, "|TInterface/ICONS/INV_Misc_Coin_01:30|t  Profession Place", GOSSIP_SENDER_MAIN, 2);
		player->ADD_GOSSIP_ITEM(9, "|TInterface/ICONS/Achievement_Arena_2v2_7:30|t Duel Zone", GOSSIP_SENDER_MAIN, 3);
		player->ADD_GOSSIP_ITEM(9, "|TInterface\\icons\\Achievement_PVP_A_01:24|t|r Training Dummies", GOSSIP_SENDER_MAIN, 16);
		player->SEND_GOSSIP_MENU(1, creature->GetGUID());
	}
		return true;
		}
		
	bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
		{
		
		player->PlayerTalkClass->ClearMenus();
		
		switch (action)
					{
		case 1:
		player->ADD_GOSSIP_ITEM(9, "|TInterface/ICONS/INV_Misc_Coin_01:30|t  Starting Gear", GOSSIP_SENDER_MAIN, 10);
		player->ADD_GOSSIP_ITEM(9, "|TInterface/ICONS/INV_Misc_Coin_01:30|t  Arena Gear", GOSSIP_SENDER_MAIN, 11);
		player->ADD_GOSSIP_ITEM(9, "|TInterface/ICONS/INV_Chest_Plate13:30|t Enhancement Vendors", GOSSIP_SENDER_MAIN, 12);
		player->ADD_GOSSIP_ITEM(9, "|TInterface\\icons\\INV_Misc_Book_06:24|t|r Class / Riding ", GOSSIP_SENDER_MAIN, 13);
		player->ADD_GOSSIP_ITEM(9, "|TInterface\\icons\\Achievement_BG_KillXEnemies_GeneralsRoom:24|t|r Arena Queue Place", GOSSIP_SENDER_MAIN, 14);
		player->ADD_GOSSIP_ITEM(9, "|TInterface\\icons\\Achievement_Reputation_KirinTor:24|t|r Transmogrifier", GOSSIP_SENDER_MAIN, 15);
		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
		return true;
		
		

		case 2: // Profession Place
		{
			player->TeleportTo(0, -219.182281f, 1638.179443f, 79.765350f, 1.288978f);
			player->PlayerTalkClass->ClearMenus();
		}
		break;

		case 3: //Duel Zone Place
		{
			player->TeleportTo(1, 5239.130371f, -4794.601074f, 690.177002f, 0.574529);
			player->PlayerTalkClass->SendCloseGossip();
		}
		break;

		case 10:  //  Starting - Mall Place
		{
			player->TeleportTo(0, -5349.660645f, -2960.515381f, 323.671600f, 3.379148f);
			player->PlayerTalkClass->ClearMenus();
		}
		break;

		case 11: //  Arena Gear - Mall Place
		{
			player->TeleportTo(0, -5305.682129f, -2984.237549f, 340.631042f, 6.113118f);
			player->PlayerTalkClass->ClearMenus();
		}
		break;
			

		case 12: // Enhancement Vendors - Mall Place
		{
			player->TeleportTo(0, -5314.827148f, -2985.888916f, 322.120697f, 1.490108f);
			player->PlayerTalkClass->ClearMenus();
		}
		break;

		case 13:   // Class Trainers - Mall Place
		{
			player->TeleportTo(0, -4817.036133f, -2719.702881f, 326.587189f, 1.553099f);
			player->PlayerTalkClass->ClearMenus();
		}
		break;

		case 14:  // Arena Organize & Arena Battlemaster/ Solo queu 3vs3 / Arena Spectator - Mall Place 
		{
			player->TeleportTo(0, -5336.968262f, -3010.926758f, 324.201843f, 3.297466f);
			player->PlayerTalkClass->ClearMenus();
		}
		break;

		case 15:   //Transmogrification - Mall Place
		{
			player->TeleportTo(0, -5378.940918f, -2971.869141f, 323.168793f, 1.816203f);
			player->PlayerTalkClass->ClearMenus();
		}
		break;

		case 16:  //Training Dummy Place
		{
			player->TeleportTo(0, -5309.075195f, -2509.201660f, 484.999420f, 3.677438f);
			player->PlayerTalkClass->ClearMenus();
		}
		break;

}
return true;
			}
};

void AddSC_Mall_GuideA()
{
	new Mall_GuideA();
}

