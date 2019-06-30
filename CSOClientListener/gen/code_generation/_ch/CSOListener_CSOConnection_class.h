/*----------------------------------------------------------------------------
 * File:  CSOListener_CSOConnection_class.h
 *
 * Class:       CSOConnection  (CSOConnection)
 * Component:   CSOListener
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef CSOLISTENER_CSOCONNECTION_CLASS_H
#define CSOLISTENER_CSOCONNECTION_CLASS_H

#ifdef	__cplusplus
extern	"C"	{
#endif

/*
 * Structural representation of application analysis class:
 *   CSOConnection  (CSOConnection)
 */
struct CSOListener_CSOConnection {
  Escher_StateNumber_t current_state;
  /* application analysis class attributes */
};



#define CSOListener_CSOConnection_MAX_EXTENT_SIZE 10
extern Escher_Extent_t pG_CSOListener_CSOConnection_extent;

/*
 * creation event:  CSOConnection1:'startup'
 * warning:  Event is not used in application - no code generated.
 */
/*
 * instance event:  CSOConnection2:'connection requested'
 * warning:  Event is not used in application - no code generated.
 */
/*
 * instance event:  CSOConnection3:'connected'
 * warning:  Event is not used in application - no code generated.
 */

/*
 * enumeration of state model states for class
 */
#define CSOListener_CSOConnection_STATE_1 1  /* state [1]:  (Idle) */
#define CSOListener_CSOConnection_STATE_2 2  /* state [2]:  (connecting) */
#define CSOListener_CSOConnection_STATE_3 3  /* state [3]:  (Connected) */
/*
 * enumeration of state model event numbers
 */
extern void CSOListener_CSOConnection_Dispatch( Escher_xtUMLEvent_t * );

#ifdef	__cplusplus
}
#endif

#endif  /* CSOLISTENER_CSOCONNECTION_CLASS_H */
