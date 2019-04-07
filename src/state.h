/*! @file
  * @brief Tilstandsmaskin med tilhørende greier
  */

//Heistilstander
typedef enum states {idle, go, stay, stop} state_t;

int stopped;

/*! @brief Kjører start-state
  * @details Kjører heisen ned til nærmeste etasje hvis heisen startes mellom to etasjer. Heisen blir stående hvis den startes i en etasje.
  *
  * @return Neste state
  */
state_t state_start();

/*! @brief Kjører idle-state.
  * @details Går rett til go-state hvis vi har bestilling i køen. Venter på ny bestilling hvis køen er tom.
  *
  * @return Neste state
  */
state_t state_idle();

/*! @brief Kjører go-state.
  * @details Sender heisen i retning av neste bestilling. Stopper hvis vi kommer over en etasje med relevant bestilling.
  *
  * @return Neste state
  */
state_t state_go();

/*! @brief Kjører stay-state
  * @details Gjør det som skal gjøres når vi står i en etasje. Åpner og lukker døra.
  *
  * @return Neste state
  */
state_t state_stay();

/*! @brief Kjører stop-state
  * @details Fikse alt som skal fikses ved nødstopp.
  *
  * @return Neste state
  */
state_t state_stop();
