/*----------------------------------------------------------------------------
 * File:  CSOListener_CSOConnection_class.c
 *
 * Class:       CSOConnection  (CSOConnection)
 * Component:   CSOListener
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#include "CSOClientListener_sys_types.h"
#include "CSOListener_classes.h"


/*
 * Statically allocate space for the instance population for this class.
 * Allocate space for the class instance and its attribute values.
 * Depending upon the collection scheme, allocate containoids (collection
 * nodes) for gathering instances into free and active extents.
 */
static Escher_SetElement_s CSOListener_CSOConnection_container[ CSOListener_CSOConnection_MAX_EXTENT_SIZE ];
static CSOListener_CSOConnection CSOListener_CSOConnection_instances[ CSOListener_CSOConnection_MAX_EXTENT_SIZE ];
Escher_Extent_t pG_CSOListener_CSOConnection_extent = {
  {0}, {0}, &CSOListener_CSOConnection_container[ 0 ],
  (Escher_iHandle_t) &CSOListener_CSOConnection_instances,
  sizeof( CSOListener_CSOConnection ), CSOListener_CSOConnection_STATE_1, CSOListener_CSOConnection_MAX_EXTENT_SIZE
  };
/*----------------------------------------------------------------------------
 * State and transition action implementations for the following class:
 *
 * Class:      CSOConnection  (CSOConnection)
 * Component:  CSOListener
 *--------------------------------------------------------------------------*/

/*
 * State 1:  [Idle]
 */
static void CSOListener_CSOConnection_act1( CSOListener_CSOConnection *, const Escher_xtUMLEvent_t * const );
static void
CSOListener_CSOConnection_act1( CSOListener_CSOConnection * self, const Escher_xtUMLEvent_t * const event )
{
}

/*
 * State 2:  [connecting]
 */
static void CSOListener_CSOConnection_act2( CSOListener_CSOConnection *, const Escher_xtUMLEvent_t * const );
static void
CSOListener_CSOConnection_act2( CSOListener_CSOConnection * self, const Escher_xtUMLEvent_t * const event )
{
}

/*
 * State 3:  [Connected]
 */
static void CSOListener_CSOConnection_act3( CSOListener_CSOConnection *, const Escher_xtUMLEvent_t * const );
static void
CSOListener_CSOConnection_act3( CSOListener_CSOConnection * self, const Escher_xtUMLEvent_t * const event )
{
}






/*
 * State-Event Matrix (SEM)
 * Row index is object (MC enumerated) current state.
 * Row zero is the uninitialized state (e.g., for creation event transitions).
 * Column index is (MC enumerated) state machine events.
 */
static const Escher_SEMcell_t CSOListener_CSOConnection_StateEventMatrix[ 3 + 1 ][ 0 ] = {
  /* row 0:  uninitialized state (for creation events) */
  {  },
  /* row 1:  CSOListener_CSOConnection_STATE_1 (Idle) */
  {  },
  /* row 2:  CSOListener_CSOConnection_STATE_2 (connecting) */
  {  },
  /* row 3:  CSOListener_CSOConnection_STATE_3 (Connected) */
  {  }
};

  /*
   * Array of pointers to the class state action procedures.
   * Index is the (MC enumerated) number of the state action to execute.
   */
  static const StateAction_t CSOListener_CSOConnection_acts[ 4 ] = {
    (StateAction_t) 0,
    (StateAction_t) CSOListener_CSOConnection_act1,  /* Idle */
    (StateAction_t) CSOListener_CSOConnection_act2,  /* connecting */
    (StateAction_t) CSOListener_CSOConnection_act3  /* Connected */
  };

  /*
   * Array of string names of the state machine names.
   * Index is the (MC enumerated) number of the state.
   */
  static const c_t * const state_name_strings[ 4 ] = {
    "",
    "Idle",
    "connecting",
    "Connected"
  };

/*
 * instance state machine event dispatching
 */
void
CSOListener_CSOConnection_Dispatch( Escher_xtUMLEvent_t * event )
{
  Escher_iHandle_t instance;
  Escher_EventNumber_t event_number = GetOoaEventNumber( event );
  Escher_StateNumber_t current_state;
  Escher_StateNumber_t next_state;
  if ( 0 != GetIsCreationEvent( event ) ) {
    instance = Escher_CreateInstance( CSOListener_DOMAIN_ID, CSOListener_CSOConnection_CLASS_NUMBER );
    if ( 0 != instance ) {
      instance->current_state = UNINITIALIZED_STATE;
      SetEventTargetInstance( event, instance );
    } else {
      /* Instance allocation failure - USER RECOVERY LOGIC IS TBD */
      UserEventNoInstanceCallout( 0 );
    }
  } else {
    instance = GetEventTargetInstance( event );
  }
  if ( 0 != instance ) {
    current_state = instance->current_state;
    if ( current_state > 3 ) {
      /* instance validation failure (object deleted while event in flight) */
      UserEventNoInstanceCallout( event_number );
    } else {
      next_state = CSOListener_CSOConnection_StateEventMatrix[ current_state ][ event_number ];
      if ( next_state <= 3 ) {
        STATE_TXN_START_TRACE( "CSOConnection", current_state, state_name_strings[ current_state ] );
        /* Update the current state and execute the state action.  */
        instance->current_state = next_state;
        ( *CSOListener_CSOConnection_acts[ next_state ] )( instance, event );
        STATE_TXN_END_TRACE( "CSOConnection", next_state, state_name_strings[ next_state ] );
      } else if ( next_state == EVENT_CANT_HAPPEN ) {
          /* event cant happen */
          UserEventCantHappenCallout( current_state, next_state, event_number );
          STATE_TXN_CH_TRACE( "CSOConnection", current_state );
      } else {
        /* empty else */
      }
    }
  }
}

