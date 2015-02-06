/*
Made by: SymboliXDEV
Edited by: Rochet2
Work %: Untested
Compile: Success
*/

#include "ScriptPCH.h"


class tc_teleporter : public CreatureScript
{
public:
    tc_teleporter() : CreatureScript("tc_teleporter") { }

    bool OnGossipHello(Player * player, Creature * creature)
    {
        if (player->IsInCombat())
        {
            player->GetSession()->SendNotification("You are in Combat");
            return true;
        }

        // Placeholders for teleports
		{
			case HORDE:
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/INV_BannerPVP_01:30|t Mall", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
			break;
			case ALLIANCE:
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/INV_BannerPVP_01:30|t Mall", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
			break;
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Achievement_Arena_3v3_5:30|t Duel Zone", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Achievement_Arena_2v2_3:30|t PvP Zone", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/INV_Misc_Gear_01:30|t Profession Mall.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/INV_Chest_Plate13:30|t Transmorgrification Mall.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+5);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/INV_Misc_Coin_05:30|t Remove my Sickness", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+10);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/INV_Misc_Coin_05:30|t Repair Items", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+11);
			player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature * creature, uint32 sender, uint32 actions)
    {
        player->PlayerTalkClass->ClearMenus();

        if (sender != GOSSIP_SENDER_MAIN || actions <= GOSSIP_ACTION_INFO_DEF)
        {
            player->CLOSE_GOSSIP_MENU();
            return true;
        }

        switch (actions)
        {
        case GOSSIP_ACTION_INFO_DEF+1:
		if (player->GetTeam() == HORDE)
		{
			player->TeleportTo(1, -1563.969971f, -4428.209961f, 7.485660f, 4.788160f);	
			player->PlayerTalkClass->SendCloseGossip();
		{
		else
		{
			player->TeleportTo(0, -8840.38f, 614.464f, 92.8506f, 0.929476f);
			player->PlayerTalkClass->SendCloseGossip();
		}
		break;

        case GOSSIP_ACTION_INFO_DEF+2: //Duel Zone
            player->TeleportTo(1, 5239.130371f, -4794.601074f, 690.177002f, 0.574529);
            player->CLOSE_GOSSIP_MENU();
            return true;

		case GOSSIP_ACTION_INFO_DEF+3: //PvP Zone 
            player->TeleportTo(0, -13245.921875f, 193.394821f, 31.008369f, 1.096788f);
            player->PlayerTalkClass->SendCloseGossip();
			break;

		case GOSSIP_ACTION_INFO_DEF+4: //Professions Mall
            player->TeleportTo(0, -219.182281f, 1638.179443f, 79.765350f, 1.288978f);
            player->PlayerTalkClass->SendCloseGossip();
            break;
        
        case GOSSIP_ACTION_INFO_DEF+5: //Transmogrification Mall
            player->TeleportTo(1, -2650.709961f, -5021.879883f, 21.182899f, 2.431570f);
            player->PlayerTalkClass->SendCloseGossip();
            break;

        case GOSSIP_ACTION_INFO_DEF+10: // Remove my siccness
            if (player->HasAura(15007))
                player->RemoveAura(15007);
            break;


        case GOSSIP_ACTION_INFO_DEF+11: // repair my items
            player->DurabilityRepairAll(false, 0.0f, false);
            break;


        default: // Close
            player->CLOSE_GOSSIP_MENU();
            return true;
        }

        OnGossipHello(player, creature);
        return true;
    }
};

void AddSC_tc_teleporter()
{
    new tc_teleporter;
}