#include <stdexcept>
#include <vector>
#include <fstream>
#include "PlayerConfiguration.h"
#include "Controller.h"
#include "HumanPlayer.h"
#include "AiPlayer.h"
#include "StandardView.h"
#include "CheatingAI.h"
#include "RandomAI.h"
#include "HuntDestroyAI.h"
#include "Attack.h" //i
BattleShip::Controller::Controller() = default;
void BattleShip::Controller::setup(const std::string &GameConfigurationFile) {
    model.loadGameConfigurationFromFile(GameConfigurationFile);
    BattleShip::StandardView screen;
    this->view =(std::make_unique<StandardView>(screen));
    PlayerConfiguration playConfig;
    playConfig = screen.getPlayerConfiguration();

    if(playConfig.numHumanPlayers > 1) {
        for (int i = 0; i < playConfig.numHumanPlayers; ++i) {
            model.addPlayer<HumanPlayer>(screen);
        }
    } else if(playConfig.numAiPlayers > 1){
        for (int i = 0; i < playConfig.numAiPlayers; ++i) {
            int choice;
            choice = screen.ChooseAI();
            switch (choice) {
              case 1:
                model.addPlayer<CheatingAI>(screen);
                break;
              case 2:
                model.addPlayer<RandomAI>(screen);
                break;
              case 3:
                model.addPlayer<HuntDestroyAI>(screen);
                break;

              default:
                break;
            }

        }
    } else if(playConfig.numHumanPlayers == 1 && playConfig.numAiPlayers == 1){
        model.addPlayer<HumanPlayer>(screen);
        int choice;
        choice = screen.ChooseAI();

        switch (choice)
        {
          case 1:
            model.addPlayer<CheatingAI>(screen);
            break;
          case 2:
            model.addPlayer<RandomAI>(screen);
            break;
          case 3:
            model.addPlayer<HuntDestroyAI>(screen);
            break;
          default:
            break;

        }

    }
    model.SetOpponents();
    model.setPlayerTurn(0);
    hasBeenSetUp = true;
    playGame();
}

void BattleShip::Controller::playGame() {
    BattleShip::StandardView screen;
    this->view = (std::make_unique<StandardView>(screen));
    if (hasBeenSetUp) {
        while (!model.isGameOver()) {
            auto temp = model.getNextMove();
            temp->enact(model, screen);
            model.changeTurn();
        }
        screen.Winner(model.getWinner());
    }
}

void BattleShip::Controller::setup(const std::string &GameConfigurationFile, int seed){
  model.loadGameConfigurationFromFile(GameConfigurationFile);
  AiPlayer::seed_random_number_generator(seed);
  BattleShip::StandardView screen;
  this->view =(std::make_unique<StandardView>(screen));
  PlayerConfiguration playConfig;
  playConfig = screen.getPlayerConfiguration();
  if(playConfig.numHumanPlayers > 1) {
    for (int i = 0; i < playConfig.numHumanPlayers; ++i) {
      model.addPlayer<HumanPlayer>(screen);
    }
  } else if(playConfig.numAiPlayers > 1){
    for (int i = 0; i < playConfig.numAiPlayers; ++i) {
      int choice;
      choice = screen.ChooseAI();
      switch (choice)
      {
        case 1:
          model.addPlayer<CheatingAI>(screen);
          break;
        case 2:
          model.addPlayer<RandomAI>(screen);
          break;
        case 3:
          model.addPlayer<HuntDestroyAI>(screen);
          break;
        default:
          break;

      }
    }
  } else if(playConfig.numHumanPlayers == 1 && playConfig.numAiPlayers == 1){
    model.addPlayer<HumanPlayer>(screen);
    int choice;
    choice = screen.ChooseAI();
    switch (choice)
    {
      case 1:
        model.addPlayer<CheatingAI>(screen);
        break;
      case 2:
        model.addPlayer<RandomAI>(screen);
        break;
      case 3:
        model.addPlayer<HuntDestroyAI>(screen);
        break;
      default:
        break;

    }
  }
  model.SetOpponents();
  model.setPlayerTurn(0);
  hasBeenSetUp = true;
  playGame();
}

void BattleShip::Controller::setup() {
  BattleShip::StandardView screen;
  this->view =(std::make_unique<StandardView>(screen));
  PlayerConfiguration playConfig;
  playConfig = screen.getPlayerConfiguration();
  if(playConfig.numHumanPlayers > 1) {
    for (int i = 0; i < playConfig.numHumanPlayers; ++i) {
      model.addPlayer<HumanPlayer>(screen);
    }
  } else if(playConfig.numAiPlayers > 1){
    for (int i = 0; i < playConfig.numAiPlayers; ++i) {
      int choice;
      choice = screen.ChooseAI();
      switch (choice)
      {
        case 1:
          model.addPlayer<CheatingAI>(screen);
          break;
        case 2:
          model.addPlayer<RandomAI>(screen);
          break;
        case 3:
          model.addPlayer<HuntDestroyAI>(screen);
          break;
        default:
          break;

      }
    }
  } else if(playConfig.numHumanPlayers == 1 && playConfig.numAiPlayers == 1){
    model.addPlayer<HumanPlayer>(screen);
    int choice;
    choice = screen.ChooseAI();
    switch (choice)
    {
      case 1:
        model.addPlayer<CheatingAI>(screen);
        break;
      case 2:
        model.addPlayer<RandomAI>(screen);
        break;
      case 3:
        model.addPlayer<HuntDestroyAI>(screen);
        break;
      default:
        break;

    }

  }
  model.SetOpponents();
  model.setPlayerTurn(0);
  hasBeenSetUp = true;
}


