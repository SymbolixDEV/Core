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
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/INV_Misc_Coin_05:30|t Remove my Sickness", GOSSIP_SENDER_MAIN, 31);
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
					player->TeleportTo(0, -1644.601196f, -1809.971802f, 79.625130f, 4.548784f);
					player->PlayerTalkClass->SendCloseGossip();
					break;
				case HORDE:
					player->TeleportTo(0, -936.645081f, -3529.008057f, 70.934006f, 1.522326f);
					player->PlayerTalkClass->SendCloseGossip();
					break;
				}
				break;

            case 1: // Gurubashi
                player->TeleportTo(0, -1405.973389f, -3236.977539f, 39.157398f, 0.383498f);
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

//Created By Philippovitch
//Shadre for:Emudevs
//Script Complete 100 %

#include "ScriptPCH.h"
using namespace std;	
		
/*Basic Menu*/
#define Menu_Whisp "Curse of Doom Top Class Killers"
#define leave "Nevermind"
/*Class E_Menu*/
#define E_Warrior "View top 5 Warrior Killers"
#define E_Paladin "View top 5 Paladin Killers"
#define E_Hunter "View top 5 Hunter Killers"
#define E_Rogue "View top 5 Rogue Killers"
#define E_Priest "View top 5 Priest Killers"
#define E_Shaman "View top 5 Shaman Killers"
#define E_Mage "View top 5 Mage Killers"
#define E_Warlock "View top 5 Warlock Killers"
#define E_Druid "View top 5 Druid Killers"
#define E_Death_knight "View top 5 Death knight Killers"
/*Top 5 Message*/
#define M_Warrior "Here is the top 5 Warrior Killers"
#define M_Paladin "Here is the top 5 Paladin Killers"
#define M_Hunter "Here is the top 5 Hunter Killers"
#define M_Rogue "Here is the top 5 Rogue Killers"
#define M_Priest "Here is the top 5 Priest Killers"
#define M_Shaman "Here is the top 5 Shaman Killers"
#define M_Mage "Here is the top 5 Mage Killers"
#define M_Warlock "Here is the top 5 Warlock Killers"
#define M_Druid "Here is the top 5 Druid Killers"
#define M_Death_knight "Here is the top 5 Death knight Killers"

class Top5_Killers : public CreatureScript
{
public:
        Top5_Killers() : CreatureScript("Top5_Killers") { }

        bool OnGossipHello(Player* player, Creature* creature)
		{
		player->ADD_GOSSIP_ITEM(0, Menu_Whisp, GOSSIP_SENDER_MAIN, 0);
		player->ADD_GOSSIP_ITEM(1, E_Warrior, GOSSIP_SENDER_MAIN, 1);
		player->ADD_GOSSIP_ITEM(1, E_Paladin, GOSSIP_SENDER_MAIN, 2);
		player->ADD_GOSSIP_ITEM(1, E_Hunter, GOSSIP_SENDER_MAIN, 3);
		player->ADD_GOSSIP_ITEM(1, E_Rogue, GOSSIP_SENDER_MAIN, 4);
		player->ADD_GOSSIP_ITEM(1, E_Priest, GOSSIP_SENDER_MAIN, 5);
		player->ADD_GOSSIP_ITEM(1, E_Shaman, GOSSIP_SENDER_MAIN, 6);
		player->ADD_GOSSIP_ITEM(1, E_Mage, GOSSIP_SENDER_MAIN, 7);
		player->ADD_GOSSIP_ITEM(1, E_Warlock, GOSSIP_SENDER_MAIN, 8);
		player->ADD_GOSSIP_ITEM(1, E_Druid, GOSSIP_SENDER_MAIN, 9);
		player->ADD_GOSSIP_ITEM(1, E_Death_knight, GOSSIP_SENDER_MAIN, 10);
		player->ADD_GOSSIP_ITEM(1, leave, GOSSIP_SENDER_MAIN, 11);
		player->SEND_GOSSIP_MENU(1, creature->GetGUID());
		return true;
		}

		bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
	{
        if (sender == GOSSIP_SENDER_MAIN)
        {
			player->PlayerTalkClass->ClearMenus();
			switch(action)
			{
			case 12:
			player->ADD_GOSSIP_ITEM(0, Menu_Whisp, GOSSIP_SENDER_MAIN, 0);
			player->ADD_GOSSIP_ITEM(1, E_Warrior, GOSSIP_SENDER_MAIN, 1);
			player->ADD_GOSSIP_ITEM(1, E_Paladin, GOSSIP_SENDER_MAIN, 2);
			player->ADD_GOSSIP_ITEM(1, E_Hunter, GOSSIP_SENDER_MAIN, 3);
			player->ADD_GOSSIP_ITEM(1, E_Rogue, GOSSIP_SENDER_MAIN, 4);
			player->ADD_GOSSIP_ITEM(1, E_Priest, GOSSIP_SENDER_MAIN, 5);
			player->ADD_GOSSIP_ITEM(1, E_Shaman, GOSSIP_SENDER_MAIN, 6);
			player->ADD_GOSSIP_ITEM(1, E_Mage, GOSSIP_SENDER_MAIN, 7);
			player->ADD_GOSSIP_ITEM(1, E_Warlock, GOSSIP_SENDER_MAIN, 8);
			player->ADD_GOSSIP_ITEM(1, E_Druid, GOSSIP_SENDER_MAIN, 9);
			player->ADD_GOSSIP_ITEM(1, E_Death_knight, GOSSIP_SENDER_MAIN, 10);
			player->ADD_GOSSIP_ITEM(1, leave, GOSSIP_SENDER_MAIN, 11);
			player->SEND_GOSSIP_MENU(1, creature->GetGUID());
			break;
			
			case 11:
			player->PlayerTalkClass->SendCloseGossip();
			break; 
			
			
			case 1: //Warrior
			{
			QueryResult result = CharacterDatabase.Query("SELECT name,totalKills FROM characters WHERE class='1' ORDER BY totalKills DESC LIMIT 5");
		    if(!result)
			  return false;

			Field * fields = NULL;
			ChatHandler(player->GetSession()).PSendSysMessage(M_Warrior);
			do
			{
			fields = result->Fetch();
			string name = fields[0].GetString();
			uint32 totalKills = fields[1].GetUInt32();
			char msg[250];
			snprintf(msg, 250, "Name: %s, With Total Kills : %u", name.c_str(), totalKills);
			ChatHandler(player->GetSession()).PSendSysMessage(msg);
			} 
			while(result->NextRow());
			player->SaveToDB();
			player->PlayerTalkClass->SendCloseGossip();
			}
			break;
			
			case 2: //Paladin
			{
			QueryResult result = CharacterDatabase.Query("SELECT name,totalKills FROM characters WHERE class='2' ORDER BY totalKills DESC LIMIT 5");
		    if(!result)
			  return false;

			Field * fields = NULL;
			ChatHandler(player->GetSession()).PSendSysMessage(M_Paladin);
			do
			{
			fields = result->Fetch();
			string name = fields[0].GetString();
			uint32 totalKills = fields[1].GetUInt32();
			char msg[250];
			snprintf(msg, 250, "Name: %s, With Total Kills : %u", name.c_str(), totalKills);
			ChatHandler(player->GetSession()).PSendSysMessage(msg);
			} 
			while(result->NextRow());
			player->SaveToDB();
			player->PlayerTalkClass->SendCloseGossip();
			}
			break;
			
			case 3: //Hunter
			{
			QueryResult result = CharacterDatabase.Query("SELECT name,totalKills FROM characters WHERE class='3' ORDER BY totalKills DESC LIMIT 5");
		    if(!result)
			  return false;

			Field * fields = NULL;
			ChatHandler(player->GetSession()).PSendSysMessage(M_Hunter);
			do
			{
			fields = result->Fetch();
			string name = fields[0].GetString();
			uint32 totalKills = fields[1].GetUInt32();
			char msg[250];
			snprintf(msg, 250, "Name: %s, With Total Kills : %u", name.c_str(), totalKills);
			ChatHandler(player->GetSession()).PSendSysMessage(msg);
			} 
			while(result->NextRow());
			player->SaveToDB();
			player->PlayerTalkClass->SendCloseGossip();
			}
			break;
			
			case 4: //Rogue
			{
			QueryResult result = CharacterDatabase.Query("SELECT name,totalKills FROM characters WHERE class='4' ORDER BY totalKills DESC LIMIT 5");
		    if(!result)
			  return false;

			Field * fields = NULL;
			ChatHandler(player->GetSession()).PSendSysMessage(M_Rogue);
			do
			{
			fields = result->Fetch();
			string name = fields[0].GetString();
			uint32 totalKills = fields[1].GetUInt32();
			char msg[250];
			snprintf(msg, 250, "Name: %s, With Total Kills : %u", name.c_str(), totalKills);
			ChatHandler(player->GetSession()).PSendSysMessage(msg);
			} 
			while(result->NextRow());
			player->SaveToDB();
			player->PlayerTalkClass->SendCloseGossip();
			}
			break;
			
			case 5: //Priest
			{
			QueryResult result = CharacterDatabase.Query("SELECT name,totalKills FROM characters WHERE class='5' ORDER BY totalKills DESC LIMIT 5");
		    if(!result)
			  return false;

			Field * fields = NULL;
			ChatHandler(player->GetSession()).PSendSysMessage(M_Priest);
			do
			{
			fields = result->Fetch();
			string name = fields[0].GetString();
			uint32 totalKills = fields[1].GetUInt32();
			char msg[250];
			snprintf(msg, 250, "Name: %s, With Total Kills : %u", name.c_str(), totalKills);
			ChatHandler(player->GetSession()).PSendSysMessage(msg);
			} 
			while(result->NextRow());
			player->SaveToDB();
			player->PlayerTalkClass->SendCloseGossip();
			}
			break;
			
			case 6: //Shaman
			{
			QueryResult result = CharacterDatabase.Query("SELECT name,totalKills FROM characters WHERE class='7' ORDER BY totalKills DESC LIMIT 5");
		    if(!result)
			  return false;

			Field * fields = NULL;
			ChatHandler(player->GetSession()).PSendSysMessage(M_Shaman);
			do
			{
			fields = result->Fetch();
			string name = fields[0].GetString();
			uint32 totalKills = fields[1].GetUInt32();
			char msg[250];
			snprintf(msg, 250, "Name: %s, With Total Kills : %u", name.c_str(), totalKills);
			ChatHandler(player->GetSession()).PSendSysMessage(msg);
			} 
			while(result->NextRow());
			player->SaveToDB();
			player->PlayerTalkClass->SendCloseGossip();
			}
			break;
			
			case 7: //Mage
			{
			QueryResult result = CharacterDatabase.Query("SELECT name,totalKills FROM characters WHERE class='8' ORDER BY totalKills DESC LIMIT 5");
		    if(!result)
			  return false;

			Field * fields = NULL;
			ChatHandler(player->GetSession()).PSendSysMessage(M_Mage);
			do
			{
			fields = result->Fetch();
			string name = fields[0].GetString();
			uint32 totalKills = fields[1].GetUInt32();
			char msg[250];
			snprintf(msg, 250, "Name: %s, With Total Kills : %u", name.c_str(), totalKills);
			ChatHandler(player->GetSession()).PSendSysMessage(msg);
			} 
			while(result->NextRow());
			player->SaveToDB();
			player->PlayerTalkClass->SendCloseGossip();
			}
			break;
			
			case 8: //warlock 
			{
			QueryResult result = CharacterDatabase.Query("SELECT name,totalKills FROM characters WHERE class='9' ORDER BY totalKills DESC LIMIT 5");
		    if(!result)
			  return false;

			Field * fields = NULL;
			ChatHandler(player->GetSession()).PSendSysMessage(M_Warlock);
			do
			{
			fields = result->Fetch();
			string name = fields[0].GetString();
			uint32 totalKills = fields[1].GetUInt32();
			char msg[250];
			snprintf(msg, 250, "Name: %s, With Total Kills : %u", name.c_str(), totalKills);
			ChatHandler(player->GetSession()).PSendSysMessage(msg);
			} 
			while(result->NextRow());
			player->SaveToDB();
			player->PlayerTalkClass->SendCloseGossip();
			}
			break;
			
			case 9: //Druid 
			{
			QueryResult result = CharacterDatabase.Query("SELECT name,totalKills FROM characters WHERE class='11' ORDER BY totalKills DESC LIMIT 5");
		    if(!result)
			  return false;

			Field * fields = NULL;
			ChatHandler(player->GetSession()).PSendSysMessage(M_Druid);
			do
			{
			fields = result->Fetch();
			string name = fields[0].GetString();
			uint32 totalKills = fields[1].GetUInt32();
			char msg[250];
			snprintf(msg, 250, "Name: %s, With Total Kills : %u", name.c_str(), totalKills);
			ChatHandler(player->GetSession()).PSendSysMessage(msg);
			} 
			while(result->NextRow());
			player->SaveToDB();
			player->PlayerTalkClass->SendCloseGossip();
			}
			break;
			
			case 10: //Death knight 
			{
			QueryResult result = CharacterDatabase.Query("SELECT name,totalKills FROM characters WHERE class='6' ORDER BY totalKills DESC LIMIT 5");
		    if(!result)
			  return false;

			Field * fields = NULL;
			ChatHandler(player->GetSession()).PSendSysMessage(M_Death_knight);
			do
			{
			fields = result->Fetch();
			string name = fields[0].GetString();
			uint32 totalKills = fields[1].GetUInt32();
			char msg[250];
			snprintf(msg, 250, "Name: %s, With Total Kills : %u", name.c_str(), totalKills);
			ChatHandler(player->GetSession()).PSendSysMessage(msg);
			} 
			while(result->NextRow());
			player->SaveToDB();
			player->PlayerTalkClass->SendCloseGossip();
			}
			break;
			}
		}
	    return true;
	  }
	};


void AddSC_Top5_Killers()
{
    new Top5_Killers();
}

#include "ScriptPCH.h"
#include "Transmogrification.h"
#define sT  sTransmogrification

class npc_enchant : public CreatureScript
{
public:
    npc_enchant() : CreatureScript("npc_enchant") { }

    bool isEquiped(Player* player, uint8 slot)
    {
        Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot);
        if (!item)
            return false;

        return true;
    }

    bool validItem(uint8 type, Item* item)
    {
        ItemTemplate const* pProto = item->GetTemplate();

        // Una Mano
        if (type == 1 && (pProto->Class == 2 && (pProto->SubClass == 0 || pProto->SubClass == 1 || pProto->SubClass == 4 || pProto->SubClass == 5 || pProto->SubClass == 6 || pProto->SubClass == 7 || pProto->SubClass == 8 || pProto->SubClass == 10 || pProto->SubClass == 13 || pProto->SubClass == 15)))
            return true;
        // Dos Manos
        if (type == 2 && (pProto->Class == 2 && (pProto->SubClass == 1 || pProto->SubClass == 5 || pProto->SubClass == 6 || pProto->SubClass == 8 || pProto->SubClass == 10)))
            return true;
        // Baston
        if (type == 3 && (pProto->Class == 2 && pProto->SubClass == 10))
            return true;
        // Escudo
        if (type == 4 && pProto->InventoryType == 14)
            return true;
        // Ranged
        if (type == 5 && pProto->Class == 2 && (pProto->SubClass == ITEM_SUBCLASS_WEAPON_CROSSBOW || pProto->SubClass == ITEM_SUBCLASS_WEAPON_BOW || pProto->SubClass == ITEM_SUBCLASS_WEAPON_GUN))
            return true;

        return false;
    }

    void Enchant(Player* player, Creature* creature, uint8 slot, uint32 enchant, uint8 type = 0, EnchantmentSlot enchSlot = PERM_ENCHANTMENT_SLOT)
    {
        Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot);

        if (!item || (type != 0 && !validItem(type, item)))
        {
            player->CLOSE_GOSSIP_MENU();
            player->GetSession()->SendNotification("|cFF00FFFF Sure I have that item equipped?|r");
            return;
        }

        SpellItemEnchantmentEntry const* enchantid = sSpellItemEnchantmentStore.LookupEntry(enchant);
        if (!enchantid)
            return;

        player->ApplyEnchantment(item, enchSlot, false);
        item->SetEnchantment(enchSlot, enchant, 0, 0);
        player->ApplyEnchantment(item, enchSlot, true);
		//player->GetSession()->SendNotification("|cffFF0000""\xc2\xa1""|cFFFFD700%s |cffFF0000encantado correctamente!", item->GetTemplate()->Name1.c_str());
        std::string color = "|cff";
        switch (item->GetTemplate()->Quality)
        {
			case 0: color += "9d9d9d"; break;
			case 1: color += "ffffff"; break;
            case 2: color += "1eff00"; break;
            case 3: color += "0070dd"; break;
            case 4: color += "a335ee"; break;
            case 5: color += "ff8000"; break;
        }
        ChatHandler(player->GetSession()).PSendSysMessage("|cffFF0000""\xc2\xa1""%s[%s] |cffFF0000enchanted properly!", color.c_str(), item->GetTemplate()->Name1.c_str());
		
        //creature->CastSpell(player, 45209, true);
        OnGossipHello(player, creature);
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
		bool count = false;

		if(isEquiped(player, EQUIPMENT_SLOT_HEAD))
		{
			Item* newItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD);
			uint32 entry = sT->GetFakeEntry(newItem->GetGUID());
			std::string icon = entry ? sT->GetItemIcon(entry, 27, 27, -14, 0) : sT->GetItemIcon(newItem->GetEntry(), 27, 27, -14, 0);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, icon+"Enchant Head", EQUIPMENT_SLOT_HEAD, GOSSIP_ACTION_INFO_DEF+2);
			count = true;
		}
		
		if(isEquiped(player, EQUIPMENT_SLOT_SHOULDERS))
		{
			Item* newItem2 = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS);
			uint32 entry2 = sT->GetFakeEntry(newItem2->GetGUID());
			std::string icon2 = entry2 ? sT->GetItemIcon(entry2, 27, 27, -14, 0) : sT->GetItemIcon(newItem2->GetEntry(), 27, 27, -14, 0);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, icon2+"Enchant Shoulders", EQUIPMENT_SLOT_SHOULDERS, GOSSIP_ACTION_INFO_DEF+3);
			count = true;
		}
		
		if(isEquiped(player, EQUIPMENT_SLOT_BACK))
		{
			Item* newItem3 = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
			uint32 entry3 = sT->GetFakeEntry(newItem3->GetGUID());
			std::string icon3 = entry3 ? sT->GetItemIcon(entry3, 27, 27, -14, 0) : sT->GetItemIcon(newItem3->GetEntry(), 27, 27, -14, 0);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, icon3+"Enchant Back", EQUIPMENT_SLOT_BACK, GOSSIP_ACTION_INFO_DEF+4);
			count = true;
		}
		
		if(isEquiped(player, EQUIPMENT_SLOT_CHEST))
		{
			Item* newItem4 = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST);
			uint32 entry4 = sT->GetFakeEntry(newItem4->GetGUID());
			std::string icon4 = entry4 ? sT->GetItemIcon(entry4, 27, 27, -14, 0) : sT->GetItemIcon(newItem4->GetEntry(), 27, 27, -14, 0);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, icon4+"Enchant Chest", EQUIPMENT_SLOT_CHEST, GOSSIP_ACTION_INFO_DEF+5);
			count = true;
		}
		
		if(isEquiped(player, EQUIPMENT_SLOT_WRISTS))
		{
			Item* newItem5 = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
			uint32 entry5 = sT->GetFakeEntry(newItem5->GetGUID());
			std::string icon5 = entry5 ? sT->GetItemIcon(entry5, 27, 27, -14, 0) : sT->GetItemIcon(newItem5->GetEntry(), 27, 27, -14, 0);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, icon5+"Enchant Wrist", EQUIPMENT_SLOT_WRISTS, GOSSIP_ACTION_INFO_DEF+6);
			count = true;
		}
		
		if(isEquiped(player, EQUIPMENT_SLOT_HANDS))
		{
			Item* newItem6 = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
			uint32 entry6 = sT->GetFakeEntry(newItem6->GetGUID());
			std::string icon6 = entry6 ? sT->GetItemIcon(entry6, 27, 27, -14, 0) : sT->GetItemIcon(newItem6->GetEntry(), 27, 27, -14, 0);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, icon6+"Enchant Hands", EQUIPMENT_SLOT_HANDS, GOSSIP_ACTION_INFO_DEF+7);
			count = true;
		}
		
		if(isEquiped(player, EQUIPMENT_SLOT_WAIST))
		{
			Item* newItem6 = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST);
			uint32 entry6 = sT->GetFakeEntry(newItem6->GetGUID());
			std::string icon6 = entry6 ? sT->GetItemIcon(entry6, 27, 27, -14, 0) : sT->GetItemIcon(newItem6->GetEntry(), 27, 27, -14, 0);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, icon6+"Enchant Waist", EQUIPMENT_SLOT_WAIST, GOSSIP_ACTION_INFO_DEF+15);
			count = true;
		}
		
		if(isEquiped(player, EQUIPMENT_SLOT_LEGS))
		{
			Item* newItem7 = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS);
			uint32 entry7 = sT->GetFakeEntry(newItem7->GetGUID());
			std::string icon7 = entry7 ? sT->GetItemIcon(entry7, 27, 27, -14, 0) : sT->GetItemIcon(newItem7->GetEntry(), 27, 27, -14, 0);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, icon7+"Enchant Legs", EQUIPMENT_SLOT_LEGS, GOSSIP_ACTION_INFO_DEF+8);
			count = true;
		}

		if(isEquiped(player, EQUIPMENT_SLOT_FEET))
		{
			Item* newItem8 = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET);
			uint32 entry8 = sT->GetFakeEntry(newItem8->GetGUID());
			std::string icon8 = entry8 ? sT->GetItemIcon(entry8, 27, 27, -14, 0) : sT->GetItemIcon(newItem8->GetEntry(), 27, 27, -14, 0);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, icon8+"Enchant Boots", EQUIPMENT_SLOT_FEET, GOSSIP_ACTION_INFO_DEF+9);
			count = true;
		}
		
        if (player->HasSkill(SKILL_ENCHANTING) && player->GetSkillValue(SKILL_ENCHANTING) >= 450)
		{
			if(isEquiped(player, EQUIPMENT_SLOT_FINGER1))
			{
				Item* newItem9 = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1);
				uint32 entry9 = sT->GetFakeEntry(newItem9->GetGUID());
				std::string icon9 = entry9 ? sT->GetItemIcon(entry9, 27, 27, -14, 0) : sT->GetItemIcon(newItem9->GetEntry(), 27, 27, -14, 0);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, icon9+"Enchant Finger 1", EQUIPMENT_SLOT_FINGER1, GOSSIP_ACTION_INFO_DEF+10);
				count = true;
			}

			if(isEquiped(player, EQUIPMENT_SLOT_FINGER2))
			{
				Item* newItem10 = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2);
				uint32 entry10 = sT->GetFakeEntry(newItem10->GetGUID());
				std::string icon10 = entry10 ? sT->GetItemIcon(entry10, 27, 27, -14, 0) : sT->GetItemIcon(newItem10->GetEntry(), 27, 27, -14, 0);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, icon10+"Enchant Finger 2", EQUIPMENT_SLOT_FINGER2, GOSSIP_ACTION_INFO_DEF+11);
				count = true;
			}
		}
		/*
		if(isEquiped(player, EQUIPMENT_SLOT_MAINHAND))
		{
			Item* newItem11 = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
			uint32 entry11 = sT->GetFakeEntry(newItem11->GetGUID());
			std::string icon11 = entry11 ? sT->GetItemIcon(entry11, 27, 27, -14, 0) : sT->GetItemIcon(newItem11->GetEntry(), 27, 27, -14, 0);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, icon11+"Enchant Main-Handed Weapon", EQUIPMENT_SLOT_MAINHAND, GOSSIP_ACTION_INFO_DEF+12);
			count = true;
		}
		
		if(isEquiped(player, EQUIPMENT_SLOT_OFFHAND))		
		{
			Item* newItem12 = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
			uint32 entry12 = sT->GetFakeEntry(newItem12->GetGUID());
			std::string icon12 = entry12 ? sT->GetItemIcon(entry12, 27, 27, -14, 0) : sT->GetItemIcon(newItem12->GetEntry(), 27, 27, -14, 0);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, icon12+"Enchant Off-handed Weapon", EQUIPMENT_SLOT_OFFHAND, GOSSIP_ACTION_INFO_DEF+13);
			count = true;
		} 
		
		if(isEquiped(player, EQUIPMENT_SLOT_RANGED))		
		{
			Item* newItem12 = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED);
			uint32 entry12 = sT->GetFakeEntry(newItem12->GetGUID());
			std::string icon12 = entry12 ? sT->GetItemIcon(entry12, 27, 27, -14, 0) : sT->GetItemIcon(newItem12->GetEntry(), 27, 27, -14, 0);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, icon12+"Enchant Ranged Weapon", EQUIPMENT_SLOT_RANGED, GOSSIP_ACTION_INFO_DEF+14);
			count = true;
		}
		*/
		
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "|TInterface/ICONS/Ability_Spy:27:27:-14:0|tClose""\xC3\xAD""Me", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+200);
		player->SEND_GOSSIP_MENU(68, creature->GetGUID());

		if(!count)
            ChatHandler(player->GetSession()).PSendSysMessage("|cfffcedbbYou have equipped that they can enchant items.|r");

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();

        switch (action)
        {
			case GOSSIP_ACTION_INFO_DEF+200:
                player->CLOSE_GOSSIP_MENU();
                break;
            case GOSSIP_ACTION_INFO_DEF+1:
                OnGossipHello(player, creature);
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "<- Back to Menu", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+50 Attack Power and 20 Critical", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+21);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+50 Attack Power and 20 Resillience", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+16);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+30 Spell and 10 Mana Regen", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+19);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+30 Spell and 20 Critical", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+20);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+29 SP and 20 Resillience", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+17);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+30 Stamina and 25 Resillience", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+18);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+37 Stamina and 20 Defense", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+22);
                player->SEND_GOSSIP_MENU(68, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+16:
                Enchant(player, creature, EQUIPMENT_SLOT_HEAD, 3795);
                break;
            case GOSSIP_ACTION_INFO_DEF+17:
                Enchant(player, creature, EQUIPMENT_SLOT_HEAD, 3797);
                break;
            case GOSSIP_ACTION_INFO_DEF+18:
                Enchant(player, creature, EQUIPMENT_SLOT_HEAD, 3842);
                break;
            case GOSSIP_ACTION_INFO_DEF+19:
                Enchant(player, creature, EQUIPMENT_SLOT_HEAD, 3819);
                break;
            case GOSSIP_ACTION_INFO_DEF+20:
                Enchant(player, creature, EQUIPMENT_SLOT_HEAD, 3820);
                break;
            case GOSSIP_ACTION_INFO_DEF+21:
                Enchant(player, creature, EQUIPMENT_SLOT_HEAD, 3817);
                break;
            case GOSSIP_ACTION_INFO_DEF+22:
                Enchant(player, creature, EQUIPMENT_SLOT_HEAD, 3818);
                break;
            case GOSSIP_ACTION_INFO_DEF+23:
                Enchant(player, creature, EQUIPMENT_SLOT_HEAD, 3815);
                break;
            case GOSSIP_ACTION_INFO_DEF+24:
                Enchant(player, creature, EQUIPMENT_SLOT_HEAD, 3816);
                break;
            case GOSSIP_ACTION_INFO_DEF+25:
                Enchant(player, creature, EQUIPMENT_SLOT_HEAD, 3814);
                break;
            case GOSSIP_ACTION_INFO_DEF+26:
                Enchant(player, creature, EQUIPMENT_SLOT_HEAD, 3812);
                break;
            case GOSSIP_ACTION_INFO_DEF+27:
                Enchant(player, creature, EQUIPMENT_SLOT_HEAD, 3813);
                break;
            case GOSSIP_ACTION_INFO_DEF+3:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "<- Back", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
				if (player->HasSkill(SKILL_INSCRIPTION) && player->GetSkillValue(SKILL_INSCRIPTION) >= 450)
                {
					player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+120 Spell and 15 Critical", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+31);
					player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+70 Spell and 8 Mana Regen", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+32);
					player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+70 Spell and 15 Critical", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+34);
					player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+70 Dodge 15 Defense", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+33);
				}
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+30 Stamina and 15 Resillience", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+28);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+40 Attack Power and 15 Resillience", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+29);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+40 Attack Power and 15 Critical", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+195);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+23 Spell and 15 Resillience", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+30);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+24 Spell and 15 Critical", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+197);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+24 Spell and 8 Mana Regen", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+196);
                player->SEND_GOSSIP_MENU(68, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+28:
                Enchant(player, creature, EQUIPMENT_SLOT_SHOULDERS, 3852);
                break;
            case GOSSIP_ACTION_INFO_DEF+29:
                Enchant(player, creature, EQUIPMENT_SLOT_SHOULDERS, 3793);
                break;
            case GOSSIP_ACTION_INFO_DEF+30:
                Enchant(player, creature, EQUIPMENT_SLOT_SHOULDERS, 3794);
                break;
            case GOSSIP_ACTION_INFO_DEF+31:
                Enchant(player, creature, EQUIPMENT_SLOT_SHOULDERS, 3835);
                break;
            case GOSSIP_ACTION_INFO_DEF+32:
                Enchant(player, creature, EQUIPMENT_SLOT_SHOULDERS, 3836);
                break;
            case GOSSIP_ACTION_INFO_DEF+33:
                Enchant(player, creature, EQUIPMENT_SLOT_SHOULDERS, 3837);
                break;
            case GOSSIP_ACTION_INFO_DEF+34:
                Enchant(player, creature, EQUIPMENT_SLOT_SHOULDERS, 3838);
                break;
            case GOSSIP_ACTION_INFO_DEF+195:
                Enchant(player, creature, EQUIPMENT_SLOT_SHOULDERS, 3808);
                break;
            case GOSSIP_ACTION_INFO_DEF+196:
                Enchant(player, creature, EQUIPMENT_SLOT_SHOULDERS, 3809);
                break;
            case GOSSIP_ACTION_INFO_DEF+197:
                Enchant(player, creature, EQUIPMENT_SLOT_SHOULDERS, 3810);
                break;
            case GOSSIP_ACTION_INFO_DEF+4:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "<- Back", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
				if (player->HasSkill(SKILL_TAILORING) && player->GetSkillValue(SKILL_TAILORING) >= 450)
                {
					player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Embroidery dark glow", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+42);
					player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Embroidery Lightweave", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+43);
					player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Embroidery Swordguard", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+44);
				}
				if (player->HasSkill(SKILL_ENGINEERING) && player->GetSkillValue(SKILL_ENGINEERING) >= 450)
				{
					player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Flexweave Underlay", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+252);
					player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Elastic Arachnoweave", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+253);
				}
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+10 Agility and increased stealth", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+35);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+22 Agility", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+40);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+23 Haste Rating", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+38);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+35 Spell Penetration", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+41);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+10 Spirit and -2% Threat", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+36);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+225 Armor", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+39);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+16 Defense", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+37);
                player->SEND_GOSSIP_MENU(68, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+35:
                Enchant(player, creature, EQUIPMENT_SLOT_BACK, 3256);
                break;
            case GOSSIP_ACTION_INFO_DEF+36:
                Enchant(player, creature, EQUIPMENT_SLOT_BACK, 3296);
                break;
            case GOSSIP_ACTION_INFO_DEF+37:
                Enchant(player, creature, EQUIPMENT_SLOT_BACK, 1951);
                break;
            case GOSSIP_ACTION_INFO_DEF+38:
                Enchant(player, creature, EQUIPMENT_SLOT_BACK, 3831);
                break;
            case GOSSIP_ACTION_INFO_DEF+39:
                Enchant(player, creature, EQUIPMENT_SLOT_BACK, 3294);
                break;
            case GOSSIP_ACTION_INFO_DEF+40:
                Enchant(player, creature, EQUIPMENT_SLOT_BACK, 1099);
                break;
            case GOSSIP_ACTION_INFO_DEF+41:
                Enchant(player, creature, EQUIPMENT_SLOT_BACK, 3243);
                break;
            case GOSSIP_ACTION_INFO_DEF+42:
                Enchant(player, creature, EQUIPMENT_SLOT_BACK, 3728);
                break;
            case GOSSIP_ACTION_INFO_DEF+43:
                Enchant(player, creature, EQUIPMENT_SLOT_BACK, 3722);
                break;
            case GOSSIP_ACTION_INFO_DEF+44:
                Enchant(player, creature, EQUIPMENT_SLOT_BACK, 3730);
                break;
            case GOSSIP_ACTION_INFO_DEF+252:
                Enchant(player, creature, EQUIPMENT_SLOT_BACK, 3605);
                break;
            case GOSSIP_ACTION_INFO_DEF+253:
                Enchant(player, creature, EQUIPMENT_SLOT_BACK, 3859);
                break;
            case GOSSIP_ACTION_INFO_DEF+5:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "<- Back", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+All Statistics", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+47);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+275 Health", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+48);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+10 Mana Regen", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+49);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+20 Resilliance", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+50);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+20 Defense", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+51);
                player->SEND_GOSSIP_MENU(68, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+47:
                Enchant(player, creature, EQUIPMENT_SLOT_CHEST, 3832);
                break;
            case GOSSIP_ACTION_INFO_DEF+48:
                Enchant(player, creature, EQUIPMENT_SLOT_CHEST, 3297);
                break;
            case GOSSIP_ACTION_INFO_DEF+49:
                Enchant(player, creature, EQUIPMENT_SLOT_CHEST, 2381);
                break;
            case GOSSIP_ACTION_INFO_DEF+50:
                Enchant(player, creature, EQUIPMENT_SLOT_CHEST, 3245);
                break;
            case GOSSIP_ACTION_INFO_DEF+51:
                Enchant(player, creature, EQUIPMENT_SLOT_CHEST, 1953);
                break;
            case GOSSIP_ACTION_INFO_DEF+6:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "<- Back", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                if (player->HasSkill(SKILL_BLACKSMITHING) && player->GetSkillValue(SKILL_BLACKSMITHING) >= 450)
		        {
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Socket Bracer", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+125);
                }
		        if (player->HasSkill(SKILL_LEATHERWORKING) && player->GetSkillValue(SKILL_LEATHERWORKING) >= 450)
                {
			        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Stamina Fur Lining", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+52);
			        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Fur Lining Spellpower", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+53);
			        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Fur Lining Attack Power", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+54);
		        }
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+18 Spirit", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+55);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+15 expertise", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+56);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+6 All Statistics", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+57);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+16 Intellect", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+58);
		        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+30 Spell Power", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+122);
		        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+50 Attack Power", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+123);
                player->SEND_GOSSIP_MENU(68, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+52:
                Enchant(player, creature, EQUIPMENT_SLOT_WRISTS, 3757);
                break;
            case GOSSIP_ACTION_INFO_DEF+53:
                Enchant(player, creature, EQUIPMENT_SLOT_WRISTS, 3758);
                break;
            case GOSSIP_ACTION_INFO_DEF+54:
                Enchant(player, creature, EQUIPMENT_SLOT_WRISTS, 3756);
                break;
            case GOSSIP_ACTION_INFO_DEF+55:
                Enchant(player, creature, EQUIPMENT_SLOT_WRISTS, 1147);
                break;
            case GOSSIP_ACTION_INFO_DEF+56:
                Enchant(player, creature, EQUIPMENT_SLOT_WRISTS, 3231);
                break;
            case GOSSIP_ACTION_INFO_DEF+57:
                Enchant(player, creature, EQUIPMENT_SLOT_WRISTS, 2661);
                break;
            case GOSSIP_ACTION_INFO_DEF+58:
                Enchant(player, creature, EQUIPMENT_SLOT_WRISTS, 1119);
                break;
            case GOSSIP_ACTION_INFO_DEF+122:
                Enchant(player, creature, EQUIPMENT_SLOT_WRISTS, 2332);
                break;
            case GOSSIP_ACTION_INFO_DEF+123:
                Enchant(player, creature, EQUIPMENT_SLOT_WRISTS, 3845);
                break;
            case GOSSIP_ACTION_INFO_DEF+125:
                Enchant(player, creature, EQUIPMENT_SLOT_WRISTS, 3717, 0, PRISMATIC_ENCHANTMENT_SLOT);
                break;
            case GOSSIP_ACTION_INFO_DEF+7:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "<- Back", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                if (player->HasSkill(SKILL_BLACKSMITHING) && player->GetSkillValue(SKILL_BLACKSMITHING) >= 450)
                {
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Socket Gloves", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+126);
                }
				if (player->HasSkill(SKILL_ENGINEERING) && player->GetSkillValue(SKILL_ENGINEERING) >= 450)
                {
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Pyro Rocket", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+121);
					player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Hyper speed Accelerators", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+250);
                }
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+16 Critical", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+59);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+10 Parry Rating and 2% Threat", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+60);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+44 Attack Power", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+61);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+28 Spell Power", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+120);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+20 Agility", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+62);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+20 Hit Rating", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+63);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+15 Expertise", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+64);
                player->SEND_GOSSIP_MENU(68, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+59:
                Enchant(player, creature, EQUIPMENT_SLOT_HANDS, 3249);
                break;
            case GOSSIP_ACTION_INFO_DEF+60:
                Enchant(player, creature, EQUIPMENT_SLOT_HANDS, 3253);
                break;
            case GOSSIP_ACTION_INFO_DEF+61:
                Enchant(player, creature, EQUIPMENT_SLOT_HANDS, 1603);
                break;
            case GOSSIP_ACTION_INFO_DEF+62:
                Enchant(player, creature, EQUIPMENT_SLOT_HANDS, 3222);
                break;
            case GOSSIP_ACTION_INFO_DEF+63:
                Enchant(player, creature, EQUIPMENT_SLOT_HANDS, 3234);
                break;
            case GOSSIP_ACTION_INFO_DEF+64:
                Enchant(player, creature, EQUIPMENT_SLOT_HANDS, 3231);
                break;
            case GOSSIP_ACTION_INFO_DEF+120:
                Enchant(player, creature, EQUIPMENT_SLOT_HANDS, 3246);
                break;
            case GOSSIP_ACTION_INFO_DEF+121:
                Enchant(player, creature, EQUIPMENT_SLOT_HANDS, 3603);
                break;
            case GOSSIP_ACTION_INFO_DEF+126:
                Enchant(player, creature, EQUIPMENT_SLOT_HANDS, 3723, 0, PRISMATIC_ENCHANTMENT_SLOT);
                break;
            case GOSSIP_ACTION_INFO_DEF+250:
                Enchant(player, creature, EQUIPMENT_SLOT_HANDS, 3604);
                break;
            case GOSSIP_ACTION_INFO_DEF+8:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "<- Back", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+40 Resilliance and 28 Stamina", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+65);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+55 Stamina and 22 Agility", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+66);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+75 Attack Power and 22 Critical", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+67);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+50 Spell Power and 20 Spirit", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+68);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+50 Spell Power and 30 Stamina", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+69);
                player->SEND_GOSSIP_MENU(68, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+65:
                Enchant(player, creature, EQUIPMENT_SLOT_LEGS, 3853);
                break;
            case GOSSIP_ACTION_INFO_DEF+66:
                Enchant(player, creature, EQUIPMENT_SLOT_LEGS, 3822);
                break;
            case GOSSIP_ACTION_INFO_DEF+67:
                Enchant(player, creature, EQUIPMENT_SLOT_LEGS, 3823);
                break;
            case GOSSIP_ACTION_INFO_DEF+68:
                Enchant(player, creature, EQUIPMENT_SLOT_LEGS, 3719);
                break;
            case GOSSIP_ACTION_INFO_DEF+69:
                Enchant(player, creature, EQUIPMENT_SLOT_LEGS, 3721);
                break;
            case GOSSIP_ACTION_INFO_DEF+9:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "<- Back", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
				if (player->HasSkill(SKILL_ENGINEERING) && player->GetSkillValue(SKILL_ENGINEERING) >= 450)
				{
					player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Nitro Boost", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+77);
				}
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+32 Attack Power", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+70);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+15 Stamina and Increased Speed", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+71);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+16 Agility", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+72);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+18 Spirit", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+73);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+7 Mana Regen on per 5s", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+74);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+12 Hit Rating and 12 Critical", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+75);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "+22 Stamina", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+76);
                player->SEND_GOSSIP_MENU(68, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+70:
                Enchant(player, creature, EQUIPMENT_SLOT_FEET, 1597);
                break;
            case GOSSIP_ACTION_INFO_DEF+71:
                Enchant(player, creature, EQUIPMENT_SLOT_FEET, 3232);
                break;
            case GOSSIP_ACTION_INFO_DEF+72:
                Enchant(player, creature, EQUIPMENT_SLOT_FEET, 983);
                break;
            case GOSSIP_ACTION_INFO_DEF+73:
                Enchant(player, creature, EQUIPMENT_SLOT_FEET, 1147);
                break;
            case GOSSIP_ACTION_INFO_DEF+74:
                Enchant(player, creature, EQUIPMENT_SLOT_FEET, 3244);
                break;
            case GOSSIP_ACTION_INFO_DEF+75:
                Enchant(player, creature, EQUIPMENT_SLOT_FEET, 3826);
                break;
            case GOSSIP_ACTION_INFO_DEF+76:
                Enchant(player, creature, EQUIPMENT_SLOT_FEET, 1075);
                break;
            case GOSSIP_ACTION_INFO_DEF+77:
                Enchant(player, creature, EQUIPMENT_SLOT_FEET, 3606);
                break;
            case GOSSIP_ACTION_INFO_DEF+10:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "<- Back", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Attack Power", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+78);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Spell Power", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+79);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Stamina", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+80);
                player->SEND_GOSSIP_MENU(68, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+78:
                Enchant(player, creature, EQUIPMENT_SLOT_FINGER1, 3839);
                break;
            case GOSSIP_ACTION_INFO_DEF+79:
                Enchant(player, creature, EQUIPMENT_SLOT_FINGER1, 3840);
                break;
            case GOSSIP_ACTION_INFO_DEF+80:
                Enchant(player, creature, EQUIPMENT_SLOT_FINGER1, 3791);
                break;
            case GOSSIP_ACTION_INFO_DEF+11:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "<- Back", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Attack Power", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+81);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Spell Power", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+82);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Stamina", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+83);
                player->SEND_GOSSIP_MENU(68, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+81:
                Enchant(player, creature, EQUIPMENT_SLOT_FINGER2, 3839);
                break;
            case GOSSIP_ACTION_INFO_DEF+82:
                Enchant(player, creature, EQUIPMENT_SLOT_FINGER2, 3840);
                break;
            case GOSSIP_ACTION_INFO_DEF+83:
                Enchant(player, creature, EQUIPMENT_SLOT_FINGER2, 3791);
                break;


            case GOSSIP_ACTION_INFO_DEF+15:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "<- Back", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Eternal Belt Buckle", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+124);
				if (player->HasSkill(SKILL_ENGINEERING) && player->GetSkillValue(SKILL_ENGINEERING) >= 450)
				{
					player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Frag Belt", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+251);
				}
                player->SEND_GOSSIP_MENU(68, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+124:
                Enchant(player, creature, EQUIPMENT_SLOT_WAIST, 3729, 0, PRISMATIC_ENCHANTMENT_SLOT);
                break;
            case GOSSIP_ACTION_INFO_DEF+251:
                Enchant(player, creature, EQUIPMENT_SLOT_WAIST, 3601);
                break;
        }
        return true;
    }
};

void AddSC_npc_enchant()
{
    new npc_enchant;
}

/************************************
*            Login Script           *
*			SymboliXDEV				*
************************************/

 
//Credit to SymbolixDEV for original.
 
class login_script : public PlayerScript
{
public:
	login_script() : PlayerScript("login_script") { }
 
	void OnLogin(Player* player)
	{
		player->GetSession()->SendNotification("|cffff0000Welcome to Curse of Doom - Tournament Realm |r");
	}
};
 
void AddSC_login_script()
{
	new login_script();
}

#include "ScriptPCH.h"
#include "Battleground.h"

class FastArenaCrystal : public GameObjectScript
{
public:

    FastArenaCrystal()
        : GameObjectScript("FastArenaCrystal")
    {
    }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (Battleground *bg = player->GetBattleground())
            if (bg->isArena())
                ChatHandler(player->GetSession()).PSendSysMessage("Players clicked: %u", bg->ClickFastStart(player, go));

        return false;
    }
};

void AddSC_fast_arena_start()
{
    new FastArenaCrystal();
}