#ifndef TALENT_FUNCTIONS_H
#define TALENT_FUNCTIONS_H

#include "Define.h"
#include <ace/Singleton.h>
#include <ace/Thread_Mutex.h>

enum templateSpells
{
	PLATE_MAIL = 750,
	MAIL       = 8737
};

enum WeaponProficiencies
{
	BLOCK           = 107,
	BOWS            = 264,
	CROSSBOWS       = 5011,
	DAGGERS         = 1180,
	FIST_WEAPONS    = 15590,
	GUNS            = 266,
	ONE_H_AXES      = 196,
	ONE_H_MACES     = 198,
	ONE_H_SWORDS    = 201,
	POLEARMS        = 200,
	SHOOT           = 5019,
	STAVES          = 227,
	TWO_H_AXES      = 197,
	TWO_H_MACES     = 199,
	TWO_H_SWORDS    = 202,
	WANDS           = 5009,
	THROW_WAR       = 2567
};

struct TalentTemplate
{
	std::string    playerClass;
	std::string    playerSpec;
	uint32         talentId;
};

struct GlyphTemplate
{
	std::string    playerClass;
	std::string    playerSpec;
	uint8          slot;
	uint32         glyph;
};

struct HumanGearTemplate
{
	std::string    playerClass;
	std::string    playerSpec;
	uint8          pos;
	uint32         itemEntry;
	uint32         enchant;
	uint32         socket1;
	uint32         socket2;
	uint32         socket3;
	uint32         bonusEnchant;
	uint32         prismaticEnchant;
};

struct AllianceGearTemplate
{
	std::string    playerClass;
	std::string    playerSpec;
	uint8          pos;
	uint32         itemEntry;
	uint32         enchant;
	uint32         socket1;
	uint32         socket2;
	uint32         socket3;
	uint32         bonusEnchant;
	uint32         prismaticEnchant;
};

struct HordeGearTemplate
{
	std::string    playerClass;
	std::string    playerSpec;
	uint8          pos;
	uint32         itemEntry;
	uint32         enchant;
	uint32         socket1;
	uint32         socket2;
	uint32         socket3;
	uint32         bonusEnchant;
	uint32         prismaticEnchant;
};

typedef std::vector<HumanGearTemplate*> HumanGearContainer;
typedef std::vector<AllianceGearTemplate*> AllianceGearContainer;
typedef std::vector<HordeGearTemplate*> HordeGearContainer;

typedef std::vector<TalentTemplate*> TalentContainer;
typedef std::vector<GlyphTemplate*> GlyphContainer;

class sTemplateNPC
{
public:
	void LoadTalentsContainer();
	void LoadGlyphsContainer();

	void LoadHumanGearContainer();
	void LoadAllianceGearContainer();
	void LoadHordeGearContainer();

	void ApplyGlyph(Player* player, uint8 slot, uint32 glyphID);
	void ApplyBonus(Player* player, Item* item, EnchantmentSlot slot, uint32 bonusEntry);

	bool OverwriteTemplate(Player* /*player*/, std::string& /*playerSpecStr*/);
	void ExtractGearTemplateToDB(Player* /*player*/, std::string& /*playerSpecStr*/);
	void ExtractTalentTemplateToDB(Player* /*player*/, std::string& /*playerSpecStr*/);
	void ExtractGlyphsTemplateToDB(Player* /*player*/, std::string& /*playerSpecStr*/);
	bool CanEquipTemplate(Player* /*player*/, std::string& /*playerSpecStr*/);

	std::string GetClassString(Player* /*player*/);
	std::string sTalentsSpec;

	void LearnTemplateTalents(Player* /*player*/);
	void LearnTemplateGlyphs(Player* /*player*/);
	void EquipTemplateGear(Player* /*player*/);

	void LearnPlateMailSpells(Player* /*player*/);

	GlyphContainer m_GlyphContainer;
	TalentContainer m_TalentContainer;

	HumanGearContainer m_HumanGearContainer;
	AllianceGearContainer m_AllianceGearContainer;
	HordeGearContainer m_HordeGearContainer;
};
#define sTemplateNpcMgr ACE_Singleton<sTemplateNPC, ACE_Null_Mutex>::instance()
#endif