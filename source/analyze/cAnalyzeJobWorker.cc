/*
 *  cAnalyzeJobWorker.cc
 *  Avida
 *
 *  Created by David on 2/18/06.
 *  Copyright 2006 Michigan State University. All rights reserved.
 *
 */

#include "cAnalyzeJobWorker.h"

#include "cAnalyzeJobQueue.h"

void cAnalyzeJobWorker::Run()
{
  cAnalyzeJob* job = NULL;
  
  while (1) {
    pthread_mutex_lock(&m_queue->m_mutex);
    job = m_queue->m_queue.Pop();
    pthread_mutex_unlock(&m_queue->m_mutex);
    
    if (job) {
      job->Run();
    } else {
      break;
    }
  }
  
  pthread_exit(NULL);
}
