/** @file
  * @brief Køsystem
  */

/** Enum med ordre. Alle verdier bortsett fra ORDER_NONE samsvarer med verdiene fra elev_button_type_t i heisdriveren (elev.h).
  */
typedef enum orders {
	ORDER_NONE = -1,               ///< Ingen bestilling.
	ORDER_UP = BUTTON_CALL_UP,     ///< Bestilling i oppoverretning.
	ORDER_DOWN = BUTTON_CALL_DOWN, ///< Bestilling i nedoverretning.
	ORDER_ALL = BUTTON_COMMAND     ///< Bestilling inni heisen eller bestilling i begge retninger.
} order_t;

/** @brief      Oppdaterer køen ut fra ny bestilling og eksisterende bestillinger.
  * @details    order = -1 (ingen bestilling) overskriver bestillingene i etasjen.
  * @param[in]  floor Etasjen der bestillinger skal oppdateres.
  * @param[in]  order Den nye bestillingen i gitt etasje.
  */
void queue_add_order(int floor, order_t order);

/** @brief Sletter alle bestillinger fra køen.
  */
void queue_clear_all();

/** @brief Sletter alle bestillinger i gitt etasje
  * @param[in] floor Etasjen bestillinger skal slettes fra
*/
void queue_clear_floor(int floor);

/** @brief Sjekker om vi skal stoppe i gitt etasje med gitt retning på heisen
  * @param[in]  floor Etasjen vi skal sjekke om vi skal stoppe i
  * @param[in]  direction Retningen vi skal sjekke om vi skal stoppe i
  *
  * @return Hvorvidt vi skal stoppe (ja/nei, 1/0).
  */
int queue_should_stop(int floor, elev_motor_direction_t direction);

/** @brief Sjekker hvorvidt det finnes noen bestillinger noe sted.
  *
  * @return Hvorvidt det finnes bestillinger i køen (ja/nei, 1/0).
  */
int queue_check_all_floors();

/** @brief Sjekker hvorvidt det finnes bestillinger over gitt etasje
  * @param[in] floor Etasjen vi skal sjekke bestillinger over.
  *
  * @return Hvorvidt det finnes bestillinger over (ja/nei, 1/0).
  */
int queue_check_above(int floor);

/** @brief Sjekker hvorvidt det finnes bestillinger under gitt etasje
  * @param[in] floor Etasjen vi skal sjekke bestillinger under.
  *
  * @return Hvorvidt det finnes bestillinger under (ja/nei, 1/0).
  */
int queue_check_below(int floor);

/** @brief Henter og returnerer bestillingen i gitt etasje.
  * @param[in] floor Etasjen vi skal hente bestillingen fram
  *
  * @return Bestillingsverdien for etasjen: NO_ORDER (ingen bestilling), ORDER_UP (bestilling oppover), ORDER_DOWN (bestilling nedover) eller ORDER_ALL (bestilling inni heisen eller bestilling i begge retninger).
  */
order_t queue_get_order(int floor);

/** @brief Oppdaterer køen med bestillinger fra knappetrykkarray i elevator-modulen. Nytter elevator_get_button_signal().
	*
  * @param[in] buttonSignals Array med nye knappetrykk
  */
void queue_update_from_button_signals();
