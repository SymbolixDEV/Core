#include "ScriptPCH.h"
#include "ScriptMgr.h"


class tc_teleporter : public CreatureScript
{
public:
	tc_teleporter() : CreatureScript("tc_teleporter") { }

	bool OnGossipHello(Player* player, Creature* creature)
	{
		if (player->IsInCombat())
        {
            player->GetSession()->SendNotification("You are in Combat");
            return true;
        }

		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Achievement_Arena_2v2_7:30|t Mall", GOSSIP_SENDER_MAIN, 3);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/INV_Chest_Plate13:30|t  Transmorgrification Mall.", GOSSIP_SENDER_MAIN, 5);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/INV_Misc_Coin_01:30|t   Profession Place", GOSSIP_SENDER_MAIN, 4);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/INV_Misc_Coin_01:30|t   Arena Que Place", GOSSIP_SENDER_MAIN, 6);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|cff888888 ----------PVP-----------", GOSSIP_SENDER_MAIN, 201);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Achievement_Arena_2v2_7:30|t Duel Zone", GOSSIP_SENDER_MAIN, 2);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Achievement_Arena_2v2_7:30|t PvP Zone", GOSSIP_SENDER_MAIN, 1);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|cff888888 ------Player Service------", GOSSIP_SENDER_MAIN, 200);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/INV_Chest_Plate13:30|t Player Tools", GOSSIP_SENDER_MAIN, 10);
		player->PlayerTalkClass->SendGossipMenu(creature->GetEntry(), creature->GetGUID());
		return true;
	}

	bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
	{
		player->PlayerTalkClass->ClearMenus();

		if (sender == GOSSIP_SENDER_MAIN)
		{
          //  player->CLOSE_GOSSIP_MENU();
         //   return true;
        }
 
		switch (action)
		{

			case 3: // Gurubashi Arena.
				switch (player->GetTeam())
				{
				case ALLIANCE:
					player->TeleportTo(0, -8840.38f, 614.464f, 92.8506f, 0.929476f);
					player->PlayerTalkClass->SendCloseGossip();
					break;
				case HORDE:
					player->TeleportTo(1, 1563.97f, -4428.21f, 7.48566f, 4.78816f);
					player->PlayerTalkClass->SendCloseGossip();
					break;
				}
				break;

            case 1: // Gurubashi
                player->TeleportTo(0, -13245.921875f, 193.394821f, 31.008369f, 1.096788f);
                player->PlayerTalkClass->SendCloseGossip();
                break;
			case 2: // Duel
                 player->TeleportTo(1, 5239.130371f, -4794.601074f, 690.177002f, 0.574529);
                player->PlayerTalkClass->SendCloseGossip();
                break;

			case 4: // Profession Place
                player->TeleportTo(0, -219.182281f, 1638.179443f, 79.765350f, 1.288978f);
                player->PlayerTalkClass->SendCloseGossip();
                break;
			case 5: //Transmog
                player->TeleportTo(1, -2650.709961f, -5021.879883f, 21.182899f, 2.431570f);
                player->PlayerTalkClass->SendCloseGossip();
                break;

			case 6: //Arena Que Place
                player->TeleportTo(530, -855.770020f, 6997.636230f, 34.994953f, 1.067743f);
                player->PlayerTalkClass->SendCloseGossip();
                break;

				case 10:
				player->ADD_GOSSIP_ITEM(4, "|TInterface/ICONS/Achievement_Arena_3v3_5:30|t <-- Back", GOSSIP_SENDER_MAIN, 1111);
				player->ADD_GOSSIP_ITEM(4, "|TInterface/ICONS/INV_Misc_Coin_05:30|t Remove my Sickness", GOSSIP_SENDER_MAIN, 31);
				player->ADD_GOSSIP_ITEM(4, "|TInterface/ICONS/INV_Misc_Coin_05:30|t Change my Race", GOSSIP_SENDER_MAIN, 34);
				player->ADD_GOSSIP_ITEM(4, "|TInterface/ICONS/INV_Misc_Coin_05:30|t Change my Faction", GOSSIP_SENDER_MAIN, 35);
				player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
				return true;

			case 34:
			{
				player->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
				player->PlayerTalkClass->SendCloseGossip();
			}
			break;

			case 35:
			{
				player->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
				player->PlayerTalkClass->SendCloseGossip();
			}
			break;

			case 31: //Remove my siccness
				if (player->HasAura(15007))
				 player->RemoveAura(15007);
			break;
 
			
			case 1111:
			 OnGossipHello(player, creature);
			 break;

			 default: // Close
			     player->CLOSE_GOSSIP_MENU();
				    return true;
				}
			
			 }
			 /* case GOSSIP_ACTION_INFO_DEF+1:
                OnGossipHello(player, creature);
                break; */
};

void AddSC_tc_teleporter()
{
	new tc_teleporter();
}