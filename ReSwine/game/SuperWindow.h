#pragma once
#include "../dxwindow.h"  // base class
#include <Windows.h>
#include <cstdint>

// adsadada
struct SMainMenu;
struct SSingleMenu;
struct SMultiLANMenu;
struct SMultiDirectIPMenu;
struct SMultiPreMenu;
struct SOptionsMenu;
struct SGameOptionsMenu;
struct SGraphicsOptionsMenu;
struct SAudioOptionsMenu;
struct SLanguageOptionsMenu;
struct SLoadMenu;
struct SChatRoomMenu;
struct STitleRoom;
struct SIntroduction;
struct SSplash;
struct SBriefingMenu;
struct SResultsMenu;
struct SGameView;
struct SMenuBackGroundView;
struct SVideoView;
struct SMarket;
struct SCredits;
struct SProperties;
struct SScaler;
struct SMulti;

struct SSuperWindow : SDXWindow
{
    // Menu/View pointers
    SMainMenu* MainMenu = nullptr;
    SSingleMenu* SingleMenu = nullptr;
    SMultiLANMenu* MultiLANMenu = nullptr;
    SMultiDirectIPMenu* MultiDirectIPMenu = nullptr;
    SMultiPreMenu* MultiPreMenu = nullptr;
    SOptionsMenu* OptionsMenu = nullptr;
    SGameOptionsMenu* GameOptionsMenu = nullptr;
    SGraphicsOptionsMenu* GraphicsOptionsMenu = nullptr;
    SAudioOptionsMenu* AudioOptionsMenu = nullptr;
    SLanguageOptionsMenu* LanguageOptionsMenu = nullptr;
    SLoadMenu* LoadGameMenu = nullptr;
    SChatRoomMenu* ChatRoomMenu = nullptr;
    STitleRoom* TitleRoom = nullptr;
    SIntroduction* Introduction = nullptr;
    SSplash* Splash = nullptr;
    SBriefingMenu* BriefingMenu = nullptr;
    SResultsMenu* ResultsMenu = nullptr;
    SGameView* GameView = nullptr;
    SMenuBackGroundView* MenuBackgroundView = nullptr;
    SVideoView* VideoView = nullptr;
    SMarket* Market = nullptr;
    SCredits* Credits = nullptr;
    SProperties* MenuIni = nullptr;
    SScaler* MenuBackgroundScaler = nullptr;

    // Flags and state
    bool bStartMultiFromCommandLine = false;
    int QuitTimer = 0;
    bool Initialized = false;

    SMulti* pMulti = nullptr;


    SSuperWindow();
    ~SSuperWindow();

    // functions
    void Create(uint32_t resource1, uint32_t resource2, const wchar_t* title);
    void Play();
};
