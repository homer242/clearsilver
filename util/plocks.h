/*
 * pthread locks specific
 *
 */

#ifndef __PLOCKS_H_
#define __PLOCKS_H_

#include <pthread.h>

#include "neo_err.h"

NEOERR *mCreate(pthread_mutex_t *mutex);
/*
 * Function:    mCreate - initialize a mutex.
 * Description: Initializes the mutex <mutex>.
 * Input:       mutex - mutex to initialize.
 * Output:      None.
 * Return:      STATUS_OK on success
 *              NERR_LOCK on failure
 * MT-Level:    Safe for unique <mutex>.
 */

void mDestroy(pthread_mutex_t *mutex);
/*
 * Function:    mDestroy - destroy a mutex.
 * Description: Destroys the mutex <mutex> that was initialized by mCreate().
 * Input:       mutex - mutex to destroy.
 * Output:      None.
 * Return:      None.
 * MT-Level:    Safe for unique <mutex>.
 */

NEOERR *mLock(pthread_mutex_t *mutex);
/*
 * Function:    mLock - lock a mutex.
 * Description: Locks the mutex <mutex>.  This call blocks until the mutex
 *              is acquired.
 * Input:       mutex - mutex to lock.
 * Output:      None.
 * Return:      STATUS_OK on success
 *              NERR_LOCK on failure
 * MT-Level:    Safe.
 */

NEOERR *mUnlock(pthread_mutex_t *mutex);
/*
 * Function:    mUnlock - unlock a mutex.
 * Description: Unlocks the mutex <mutex>.
 * Input:       mutex - mutex to unlock.
 * Output:      None.
 * Return:      STATUS_OK on success
 *              NERR_LOCK on failure
 * MT-Level:    Safe.
 */

NEOERR *cCreate(pthread_cond_t *cond);
/*
 * Function:    cCreate - initialize a condition variable.
 * Description: Initializes the condition variable <cond>.
 * Input:       cond - condition variable to initialize.
 * Output:      None.
 * Return:      STATUS_OK on success
 *              NERR_LOCK on failure
 * MT-Level:    Safe for unique <cond>.
 */

void cDestroy(pthread_cond_t *cond);
/*
 * Function:    cDestroy - destroy a condition variable.
 * Description: Destroys the condition variable <cond> that was 
 *              initialized by cCreate().
 * Input:       cond - condition variable to destroy.
 * Output:      None.
 * Return:      None.
 * MT-Level:    Safe for unique <cond>.
 */

NEOERR *cWait(pthread_cond_t *cond, pthread_mutex_t *mutex);
/*
 * Function:    cWait - wait a condition variable signal.
 * Description: Waits for a signal on condition variable <cond>.
 *              The mutex <mutex> must be locked by the thread.
 * Input:       cond - condition variable to wait on.
 *              mutex - locked mutex to protect <cond>.
 * Output:      None.
 * Return:      STATUS_OK on success
 *              NERR_LOCK on failure
 * MT-Level:    Safe.
 */

NEOERR *cBroadcast(pthread_cond_t *cond);
/*
 * Function:    cBroadcast - broadcast signal to all waiting threads.
 * Description: Broadcasts a signal to all threads waiting on condition
 *              variable <cond>.
 * Input:       cond - condition variable to broadcast on.
 * Output:      None.
 * Return:      STATUS_OK on success
 *              NERR_LOCK on failure
 * MT-Level:    Safe.
 */

NEOERR *cSignal(pthread_cond_t *cond);
/*
 * Function:    cSignal - send signal to one waiting thread.
 * Description: Sends a signal to one thread waiting on condition
 *              variable <cond>.
 * Input:       cond - condition variable to send signal on.
 * Output:      None.
 * Return:      STATUS_OK on success
 *              NERR_LOCK on failure
 * MT-Level:    Safe.
 */

#endif
