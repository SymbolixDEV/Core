/*
Author: Rochet2
Source: http://emudevs.com/showthread.php/53-Lua-Enchant-visual-system-and-gossip
Converted to C++

About:
All weapons looted have a 25% chance to have a random enchant *visual*
This is purely visual fun and the visual will be replaced when the weapon is enchanted.

This script is 100% automatic. Just add it to your source.
*/

#define CHANCE  0.25

// Do not edit anything below

#include "ScriptPCH.h"

static const uint32 ItemEnchants[] = {3789, 3854, 3273, 3225, 3870, 1899, 2674, 2675, 2671, 2672, 3365, 2673, 2343, 425, 3855, 1894, 1103, 1898, 3345, 1743, 3093, 1900, 3846, 1606, 283, 1, 3265, 2, 3, 3266, 1903, 13, 26, 7, 803, 1896, 2666, 25};
static const uint32 ItemEnchants_size = sizeof(ItemEnchants)/sizeof(*ItemEnchants);
typedef UNORDERED_MAP<uint32, uint32> EnchantStoreType;
typedef UNORDERED_MAP<uint32, EnchantStoreType> ItemStoreType;
static ItemStoreType ItemStore;

uint32 GetItemEnchantVisual(Player* player, Item* item)
{
    if (!player || !item)
        return 0;
    
    uint32 iguid = item->GetGUIDLow();
    EnchantStoreType* EnchantStore = NULL;
    ItemStoreType::iterator it = ItemStore.find(player->GetGUIDLow());
    if (it != ItemStore.end())
        EnchantStore = &it->second;
    bool hasVisual = (EnchantStore && EnchantStore->find(iguid) != EnchantStore->end());
    uint32 enchant = item->GetEnchantmentId(PERM_ENCHANTMENT_SLOT);

    if (enchant)
    {
        if (hasVisual)
        {
            CharacterDatabase.PExecute("DELETE FROM custom_item_enchant_visuals WHERE iguid = %u", iguid);
            EnchantStore->erase(iguid);
            player->SaveToDB();
        }
        return enchant;
    }
    if (hasVisual)
        return (*EnchantStore)[iguid];
    return 0;
}

void SetRandomEnchantVisual(Player* player, Item* item)
{
    if (!player || !item)
        return;
    const ItemTemplate* temp = item->GetTemplate();
    if (temp->Class != ITEM_CLASS_WEAPON)
        return;
    if (temp->SubClass == ITEM_SUBCLASS_WEAPON_BOW ||
        temp->SubClass == ITEM_SUBCLASS_WEAPON_GUN ||
        temp->SubClass == ITEM_SUBCLASS_WEAPON_obsolete ||
        temp->SubClass == ITEM_SUBCLASS_WEAPON_FIST ||
        temp->SubClass == ITEM_SUBCLASS_WEAPON_THROWN ||
        temp->SubClass == ITEM_SUBCLASS_WEAPON_SPEAR ||
        temp->SubClass == ITEM_SUBCLASS_WEAPON_CROSSBOW ||
        temp->SubClass == ITEM_SUBCLASS_WEAPON_WAND ||
        temp->SubClass == ITEM_SUBCLASS_WEAPON_FISHING_POLE)
        return;
    if (rand_norm() >= CHANCE)
        return;

    uint32 enchant = ItemEnchants[urand(0, ItemEnchants_size)];
    uint32 iguid = item->GetGUIDLow();
    CharacterDatabase.PExecute("REPLACE INTO custom_item_enchant_visuals (iguid, display) VALUES (%u, %u)", iguid, enchant);
    ItemStore[player->GetGUIDLow()][iguid] = enchant;
    player->SaveToDB();
    player->SetVisibleItemSlot(EQUIPMENT_SLOT_MAINHAND, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND));
    player->SetVisibleItemSlot(EQUIPMENT_SLOT_OFFHAND, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND));
}

class item_enchant_visuals : public PlayerScript
{
public:
    item_enchant_visuals() : PlayerScript("item_enchant_visuals")
    {
        const char* sql = 
            "CREATE TABLE IF NOT EXISTS `custom_item_enchant_visuals` ("
            "    `iguid` INT(10) UNSIGNED NOT NULL COMMENT 'item DB guid',"
            "    `display` INT(10) UNSIGNED NOT NULL COMMENT 'enchantID',"
            "    PRIMARY KEY (`iguid`)"
            ")"
            "COMMENT='stores the enchant IDs for the visuals'"
            "COLLATE='latin1_swedish_ci'"
            "ENGINE=InnoDB;";
        CharacterDatabase.DirectExecute(sql);
        CharacterDatabase.DirectExecute("DELETE FROM custom_item_enchant_visuals WHERE NOT EXISTS(SELECT 1 FROM item_instance WHERE custom_item_enchant_visuals.iguid = item_instance.guid)");
    }

    void OnLogin(Player* player)
    {
        QueryResult result = CharacterDatabase.PQuery("SELECT iguid, display FROM custom_item_enchant_visuals WHERE iguid IN(SELECT guid FROM item_instance WHERE owner_guid = %u)", player->GetGUIDLow());
        if (result)
        {
            uint32 pguid = player->GetGUIDLow();
            do
            {
                uint32 iguid = result->Fetch()[0].GetUInt32();
                uint32 display = result->Fetch()[1].GetUInt32();
                ItemStore[pguid][iguid] = display;
            }
            while (result->NextRow());
            
            player->SetVisibleItemSlot(EQUIPMENT_SLOT_MAINHAND, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND));
            player->SetVisibleItemSlot(EQUIPMENT_SLOT_OFFHAND, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND));
        }
    }

    void OnLogout(Player* player)
    {
        ItemStore.erase(player->GetGUIDLow());
    }
};

void AddSC_item_enchant_visuals()
{
    new item_enchant_visuals;
}
#undef CHANCE
