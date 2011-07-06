#include "plocks.h"

NEOERR *mCreate(pthread_mutex_t *mutex) 
{
  int err;

  if((err = pthread_mutex_init(mutex, NULL))) {
    return nerr_raise (NERR_LOCK, "Unable to initialize mutex: %s", 
	strerror(err));
  }

  return STATUS_OK;
}

void mDestroy(pthread_mutex_t *mutex) 
{

  pthread_mutex_destroy(mutex);  

  return;
}

NEOERR *mLock(pthread_mutex_t *mutex) 
{
  int err;

  if((err = pthread_mutex_lock(mutex)))
    return nerr_raise(NERR_LOCK, "Mutex lock failed: %s", strerror(err));

  return STATUS_OK;
}

NEOERR *mUnlock(pthread_mutex_t *mutex) 
{
  int err;

  if((err = pthread_mutex_unlock(mutex)))
    return nerr_raise(NERR_LOCK, "Mutex unlock failed: %s", strerror(err));

  return STATUS_OK;
}

NEOERR *cCreate(pthread_cond_t *cond) 
{
  int err;

  if((err = pthread_cond_init(cond, NULL))) {
    return nerr_raise(NERR_LOCK, "Unable to initialize condition variable: %s", 
	strerror(err));
  }

  return STATUS_OK;
}

void cDestroy(pthread_cond_t *cond) 
{
  pthread_cond_destroy(cond);  

  return;
}

NEOERR *cWait(pthread_cond_t *cond, pthread_mutex_t *mutex) 
{
  int err;

  if((err = pthread_cond_wait(cond, mutex)))
    return nerr_raise(NERR_LOCK, "Condition wait failed: %s", strerror(err));

  return STATUS_OK;
}

NEOERR *cBroadcast(pthread_cond_t *cond) 
{
  int err;

  if((err = pthread_cond_broadcast(cond)))
    return nerr_raise(NERR_LOCK, "Condition broadcast failed: %s", 
	strerror(err));

  return STATUS_OK;
}

NEOERR *cSignal(pthread_cond_t *cond) 
{
  int err;

  if((err = pthread_cond_signal(cond)))
    return nerr_raise (NERR_LOCK, "Condition signal failed: %s", strerror(err));

  return STATUS_OK;
}
