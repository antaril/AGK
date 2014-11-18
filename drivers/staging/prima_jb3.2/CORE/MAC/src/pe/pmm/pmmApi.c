/*
<<<<<<< HEAD
 * Copyright (c) 2012-2013, The Linux Foundation. All rights reserved.
 *
 * Previously licensed under the ISC license by Qualcomm Atheros, Inc.
 *
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */
/*
=======
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
 * Copyright (c) 2012, The Linux Foundation. All rights reserved.
 *
 * Previously licensed under the ISC license by Qualcomm Atheros, Inc.
 *
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */
<<<<<<< HEAD
=======

>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
/*
 * Airgo Networks, Inc proprietary. All rights reserved.
 * This file pmmApi.cc contains functions related to the API exposed
 * by power management module
 *
 * Author:      Sandesh Goel
 * Date:        02/25/02
 * History:-
 * Date            Modified by    Modification Information
 * --------------------------------------------------------------------
 *
 */

#include "palTypes.h"
#include "wniCfgSta.h"

#include "sirCommon.h"
#include "aniGlobal.h"

#include "schApi.h"
#include "limApi.h"
#include "limSendMessages.h"
#include "cfgApi.h"
#include "limSessionUtils.h"
#include "limFT.h"


#include "pmmApi.h"
#include "pmmDebug.h"
#include "sirApi.h"
#include "wmmApsd.h"

#include "limSendSmeRspMessages.h"
#include "limTimerUtils.h"
#include "limTrace.h"
#include "limUtils.h"
#include "VossWrapper.h"
#ifdef INTEGRATION_READY
#include "vos_status.h" //VOS_STATUS
#include "vos_mq.h"     //vos_mq_post_message()
#endif

#include "wlan_qct_wda.h"

// --------------------------------------------------------------------
/**
 * pmmInitialize
 *
 * FUNCTION:
 * Initialize PMM module
 *
 * LOGIC:
 *
 * ASSUMPTIONS:
 *
 * NOTE:
 *
 * @param mode
 * @param rate
 * @return None
 */

tSirRetStatus
pmmInitialize(tpAniSirGlobal pMac)
{

<<<<<<< HEAD
=======
#if (WNI_POLARIS_FW_PRODUCT == AP)
    pMac->pmm.gPmmNextSta = 0;
    pMac->pmm.gPmmNumSta = 0;
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

    pmmResetStats(pMac);

    pMac->pmm.gPmmBeaconInterval = WNI_CFG_BEACON_INTERVAL_STADEF;
    pMac->pmm.gPmmState = ePMM_STATE_READY;


<<<<<<< HEAD
=======
#ifdef ANI_PRODUCT_TYPE_AP

    palZeroMemory(pMac->hHdd,
                    pMac->pmm.gPmmTim.pTim, sizeof(tANI_U8)*pMac->lim.maxStation);

    palZeroMemory(pMac->hHdd,
                     pMac->pmm.gPmmTim.pStaInfo, sizeof(*pMac->pmm.gPmmTim.pStaInfo)*pMac->lim.maxStation);

    palZeroMemory(pMac->hHdd,
                    pMac->pmm.gpPmmStaState, sizeof(tPmmStaState)*pMac->lim.maxStation);

    palZeroMemory(pMac->hHdd,
                    pMac->pmm.gpPmmPSState, sizeof(tANI_U8)*pMac->lim.maxStation);
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

    pMac->pmm.inMissedBeaconScenario = FALSE;

    return eSIR_SUCCESS;
}

// --------------------------------------------------------------------
/**
 * pmmResetStats
 *
 * FUNCTION:
 * Resets the statistics
 *
 * LOGIC:
 *
 * ASSUMPTIONS:
 *
 * NOTE:
 *
 * @param pMac
 *
 * @return None
 */

void
pmmResetStats(void *pvMac)
{
    tpAniSirGlobal pMac = (tpAniSirGlobal)pvMac;

    pMac->pmm.BmpsmaxSleepTime = 0;
    pMac->pmm.BmpsavgSleepTime = 0;
    pMac->pmm.BmpsminSleepTime = 0;
    pMac->pmm.BmpscntSleep = 0;

    pMac->pmm.BmpsmaxTimeAwake = 0;
    pMac->pmm.BmpsavgTimeAwake = 0;
    pMac->pmm.BmpsminTimeAwake = 0;
    pMac->pmm.BmpscntAwake = 0;

    pMac->pmm.BmpsWakeupTimeStamp = 0;
    pMac->pmm.BmpsSleepTimeStamp = 0;

    pMac->pmm.BmpsHalReqFailCnt = 0;
    pMac->pmm.BmpsInitFailCnt = 0;
    pMac->pmm.BmpsInitFailCnt= 0;
    pMac->pmm.BmpsInvStateCnt= 0;
    pMac->pmm.BmpsPktDrpInSleepMode= 0;
    pMac->pmm.BmpsReqInInvalidRoleCnt= 0;
    pMac->pmm.BmpsSleeReqFailCnt= 0;
    pMac->pmm.BmpsWakeupIndCnt= 0;

    pMac->pmm.ImpsWakeupTimeStamp = 0;
    pMac->pmm.ImpsSleepTimeStamp = 0;
    pMac->pmm.ImpsMaxTimeAwake = 0;
    pMac->pmm.ImpsMinTimeAwake = 0;
    pMac->pmm.ImpsAvgTimeAwake = 0;
    pMac->pmm.ImpsCntAwake = 0;

    pMac->pmm.ImpsCntSleep = 0;
    pMac->pmm.ImpsMaxSleepTime = 0;
    pMac->pmm.ImpsMinSleepTime = 0;
    pMac->pmm.ImpsAvgSleepTime = 0;

    pMac->pmm.ImpsSleepErrCnt = 0;
    pMac->pmm.ImpsWakeupErrCnt = 0;
    pMac->pmm.ImpsLastErr = 0;
    pMac->pmm.ImpsInvalidStateCnt = 0;

    return;
}



// --------------------------------------------------------------------
/**
 * pmmInitBmpsResponseHandler
 *
 * FUNCTION:
 * This function processes the SIR_HAL_ENTER_BMPS_RSP from HAL.
 * If the response is successful, it puts PMM in ePMM_STATE_BMP_SLEEP state
 * and sends back success response to PMC.
 *
 * LOGIC:
 *
 * ASSUMPTIONS:
 *
 * NOTE:
 *
 * @param
 * @return None
 */

<<<<<<< HEAD
void pmmInitBmpsResponseHandler(tpAniSirGlobal pMac, tpSirMsgQ limMsg )
=======
void pmmInitBmpsResponseHandler(tpAniSirGlobal pMac, eHalStatus rspStatus)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
{


    tPmmState nextState = pMac->pmm.gPmmState;
    tSirResultCodes retStatus = eSIR_SME_SUCCESS;
    tpPESession     psessionEntry;
<<<<<<< HEAD
    tpEnterBmpsParams pEnterBmpsParams;
=======
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

    /* we need to process all the deferred messages enqueued since
     * the initiating the SIR_HAL_ENTER_BMPS_REQ.
    */
    SET_LIM_PROCESS_DEFD_MESGS(pMac, true);

    if(pMac->pmm.gPmmState != ePMM_STATE_BMPS_WT_INIT_RSP)
    {
        PELOGE(pmmLog(pMac, LOGE,
<<<<<<< HEAD
            FL("pmmBmps: Received 'InitPwrSaveRsp' while in incorrect state: %d"),
=======
            FL("pmmBmps: Received 'InitPwrSaveRsp' while in incorrect state: %d\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            pMac->pmm.gPmmState);)

        retStatus = eSIR_SME_INVALID_PMM_STATE;
        pmmBmpsUpdateInvalidStateCnt(pMac);
        goto failure;
    }

<<<<<<< HEAD
    if (NULL == limMsg->bodyptr)
    {
        PELOGE(pmmLog(pMac, LOGE, FL("pmmBmps: Received SIR_HAL_ENTER_BMPS_RSP with NULL "));)
        goto failure;
    }
    pEnterBmpsParams = (tpEnterBmpsParams)(limMsg->bodyptr);

    //if response is success, then set PMM to BMPS_SLEEP state and send response back to PMC.
    //If response is failure, then send the response back to PMC and reset its state.
    if(pEnterBmpsParams->status == eHAL_STATUS_SUCCESS)
    {
        PELOG2(pmmLog(pMac, LOG2,
            FL("pmmBmps: Received successful response from HAL to enter BMPS_POWER_SAVE "));)
=======
    //if response is success, then set PMM to BMPS_SLEEP state and send response back to PMC.
    //If response is failure, then send the response back to PMC and reset its state.
    if(rspStatus == eHAL_STATUS_SUCCESS)
    {
        PELOG2(pmmLog(pMac, LOG2,
            FL("pmmBmps: Received successful response from HAL to enter BMPS_POWER_SAVE \n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

        pMac->pmm.gPmmState = ePMM_STATE_BMPS_SLEEP;

        // Update sleep statistics
        pmmUpdatePwrSaveStats(pMac);

        // Disable background scan mode
        pMac->sys.gSysEnableScanMode = false;

        if (pMac->lim.gLimTimersCreated)
        {
            /* Disable heartbeat timer as well */
            if(pMac->lim.limTimers.gLimHeartBeatTimer.pMac)
            {
                MTRACE(macTrace(pMac, TRACE_CODE_TIMER_DEACTIVATE, NO_SESSION, eLIM_HEART_BEAT_TIMER));
                tx_timer_deactivate(&pMac->lim.limTimers.gLimHeartBeatTimer);
            }
        }
        limSendSmeRsp(pMac, eWNI_PMC_ENTER_BMPS_RSP,  retStatus, 0, 0);
    }
    else
    {
        //if init req failed, then go back to WAKEUP state.
        PELOGE(pmmLog(pMac, LOGE,
<<<<<<< HEAD
            FL("pmmBmps: BMPS_INIT_PWR_SAVE_REQ failed, informing SME"));)
=======
            FL("pmmBmps: BMPS_INIT_PWR_SAVE_REQ failed, informing SME\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

        pmmBmpsUpdateInitFailureCnt(pMac);
        nextState = ePMM_STATE_BMPS_WAKEUP;
        retStatus = eSIR_SME_BMPS_REQ_FAILED;
        goto failure;
    }
    return;

failure:
    psessionEntry = peGetValidPowerSaveSession(pMac);
    if(psessionEntry != NULL)
    {
       if (pMac->lim.gLimTimersCreated && pMac->lim.limTimers.gLimHeartBeatTimer.pMac)
       {
           if(VOS_TRUE != tx_timer_running(&pMac->lim.limTimers.gLimHeartBeatTimer))
           {
               PELOGE(pmmLog(pMac, LOGE, FL("Unexpected heartbeat timer not running"));)
               limReactivateHeartBeatTimer(pMac, psessionEntry);
           }
       }
    }

    //Generate an error response back to PMC
    pMac->pmm.gPmmState = nextState;
    pmmBmpsUpdateSleepReqFailureCnt(pMac);
    limSendSmeRsp(pMac, eWNI_PMC_ENTER_BMPS_RSP, retStatus, 0, 0);
    return;

}

// --------------------------------------------------------------------
/**
 * pmmExitBmpsRequestHandler
 *
 * FUNCTION:
 * This function will send the wakeup message to HAL
 *
 * LOGIC:
 *
 * ASSUMPTIONS:
 *
 * NOTE:
 *
 * @param pMac  pointer to Global Mac structure.

 * @return None
 */

void pmmExitBmpsRequestHandler(tpAniSirGlobal pMac, tpExitBmpsInfo pExitBmpsInfo)
{
    tSirResultCodes respStatus = eSIR_SME_SUCCESS;

    tPmmState origState = pMac->pmm.gPmmState;

#ifdef FEATURE_WLAN_DIAG_SUPPORT 
    limDiagEventReport(pMac, WLAN_PE_DIAG_EXIT_BMPS_REQ_EVENT, peGetValidPowerSaveSession(pMac), 0, (tANI_U16)pExitBmpsInfo->exitBmpsReason);
#endif //FEATURE_WLAN_DIAG_SUPPORT

    if (NULL == pExitBmpsInfo)
    {
        respStatus = eSIR_SME_BMPS_REQ_REJECT;
<<<<<<< HEAD
        PELOGW(pmmLog(pMac, LOGW, FL("pmmBmps: Rcvd EXIT_BMPS with NULL body"));)
=======
        PELOGW(pmmLog(pMac, LOGW, FL("pmmBmps: Rcvd EXIT_BMPS with NULL body\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        goto failure;
    }

    /* PMC is not aware of Background scan, which is done in
     * BMPS mode while Nth Beacon is delivered. Essentially, PMC
     * can request the device to get out of power-save while
     * background scanning is happening. since, the device is already
     * out of powersave, just inform that device is out of powersave
     */
    if(limIsSystemInScanState(pMac))
    {
        PELOGW(pmmLog(pMac, LOGW, 
<<<<<<< HEAD
            FL("pmmBmps: Device is already awake and scanning, returning success to PMC "));)
=======
            FL("pmmBmps: Device is already awake and scanning, returning success to PMC \n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        limSendSmeRsp(pMac, eWNI_PMC_EXIT_BMPS_RSP, respStatus, 0, 0);
        return;
    }

    /* send wakeup request, only when in sleep state */
<<<<<<< HEAD
    PELOGW(pmmLog(pMac, LOGW, FL("pmmBmps: Sending eWNI_PMC_EXIT_BMPS_REQ to HAL"));)
=======
    PELOGW(pmmLog(pMac, LOGW, FL("pmmBmps: Sending eWNI_PMC_EXIT_BMPS_REQ to HAL\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    if (pMac->pmm.gPmmState == ePMM_STATE_BMPS_SLEEP)
    {
        /* Store the reason code for exiting BMPS. This value will be
         * checked when PMM receives SIR_HAL_EXIT_BMPS_RSP from HAL
         */
        pMac->pmm.gPmmExitBmpsReasonCode = pExitBmpsInfo->exitBmpsReason;
        palFreeMemory( pMac->hHdd, (tANI_U8 *) pExitBmpsInfo);

        PELOGW(pmmLog(pMac, LOGW, 
<<<<<<< HEAD
            FL("pmmBmps: Rcvd EXIT_BMPS with reason code%d "), pMac->pmm.gPmmExitBmpsReasonCode);)
=======
            FL("pmmBmps: Rcvd EXIT_BMPS with reason code%d \n"), pMac->pmm.gPmmExitBmpsReasonCode);)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838


        // Set PMM to BMPS_WT_WAKEUP_RSP state
        pMac->pmm.gPmmState = ePMM_STATE_BMPS_WT_WAKEUP_RSP;
        if(pmmSendChangePowerSaveMsg(pMac) !=  eSIR_SUCCESS)
        {
            /* Wakeup request failed */
            respStatus = eSIR_SME_BMPS_REQ_REJECT;
            pmmBmpsUpdateHalReqFailureCnt(pMac);
            goto failure;
        }
        else
        {
            PELOG1(pmmLog(pMac, LOG1,
<<<<<<< HEAD
                          FL("pmmBmps: eWNI_PMC_EXIT_BMPS_REQ was successfully sent to HAL"));)
=======
                          FL("pmmBmps: eWNI_PMC_EXIT_BMPS_REQ was successfully sent to HAL\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        }
    }
    else
    {
        PELOGE(pmmLog(pMac, LOGE, 
<<<<<<< HEAD
                      FL("pmmBmps: eWNI_PMC_EXIT_BMPS_REQ received in invalid state: %d"),
=======
                      FL("pmmBmps: eWNI_PMC_EXIT_BMPS_REQ received in invalid state: %d\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            pMac->pmm.gPmmState );)

        respStatus = eSIR_SME_INVALID_PMM_STATE;
        pmmBmpsUpdateInvalidStateCnt(pMac);
<<<<<<< HEAD
        palFreeMemory( pMac->hHdd, (tANI_U8 *) pExitBmpsInfo);
=======
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        goto failure;
    }
    return;

failure:
    pMac->pmm.gPmmState = origState;
    pmmBmpsUpdateWakeupReqFailureCnt(pMac);
    limSendSmeRsp(pMac, eWNI_PMC_EXIT_BMPS_RSP, respStatus, 0, 0);
}


// --------------------------------------------------------------------
/**
 * pmmInitBmpsPwrSave
 *
 * FUNCTION:
 * This function process the eWNI_PMC_ENTER_PMC_REQ from PMC.
 * It checks for certain conditions before it puts PMM into
 * BMPS power save state: ePMM_STATE_BMPS_WT_INIT_RSP
 * It also invokes pmmSendInitPowerSaveMsg() to send ENTER_BMPS_REQ
 * to HAL.
 *
 * LOGIC:
 *
 * ASSUMPTIONS:
 *
 * NOTE:
 *
 * @param mode can be either 0(sleep mode) or 1 (active mode)
 * @param pMac  pointer to Global Mac structure.

 * @return None
 */


void pmmInitBmpsPwrSave(tpAniSirGlobal pMac)
{
    tSirRetStatus   retStatus = eSIR_SUCCESS;
    tSirResultCodes respStatus = eSIR_SME_SUCCESS;
    tpPESession     psessionEntry;

    tPmmState origState = pMac->pmm.gPmmState;

    if((psessionEntry = peGetValidPowerSaveSession(pMac))== NULL)
    {
        respStatus = eSIR_SME_BMPS_REQ_REJECT;
        goto failure;
    }
<<<<<<< HEAD
#ifndef WLAN_ACTIVEMODE_OFFLOAD_FEATURE
    // sending beacon filtering information down to HAL
    if (limSendBeaconFilterInfo(pMac, psessionEntry) != eSIR_SUCCESS)
    {
        pmmLog(pMac, LOGE, FL("Fail to send Beacon Filter Info "));
    }
#else
    if(!IS_ACTIVEMODE_OFFLOAD_FEATURE_ENABLE)
    {
        if (limSendBeaconFilterInfo(pMac, psessionEntry) != eSIR_SUCCESS)
        {
            pmmLog(pMac, LOGE, FL("Fail to send Beacon Filter Info "));
        }
    }
#endif

=======
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
#ifdef FEATURE_WLAN_DIAG_SUPPORT 
    limDiagEventReport(pMac, WLAN_PE_DIAG_ENTER_BMPS_REQ_EVENT, psessionEntry, 0, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT

    if ( ((pMac->pmm.gPmmState != ePMM_STATE_READY) &&
         (pMac->pmm.gPmmState != ePMM_STATE_BMPS_WAKEUP)) ||
         limIsSystemInScanState(pMac) ||
         limIsChanSwitchRunning(pMac) ||
         limIsInQuietDuration(pMac) )
    {
        PELOGE(pmmLog(pMac, LOGE, 
<<<<<<< HEAD
            FL("pmmBmps: BMPS Request received in invalid state PMM=%d, SME=%d, rejecting the initpwrsave request"),
=======
            FL("pmmBmps: BMPS Request received in invalid state PMM=%d, SME=%d, rejecting the initpwrsave request\n"), 
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            pMac->pmm.gPmmState, pMac->lim.gLimSmeState);)

        respStatus = eSIR_SME_INVALID_PMM_STATE;
        pmmBmpsUpdateInvalidStateCnt(pMac);
        goto failure;
    }

    //If we are in a missed beacon scenario, we should not be attempting to enter BMPS as heartbeat probe is going on
    if(pMac->pmm.inMissedBeaconScenario)
    {
       if (pMac->lim.gLimTimersCreated && pMac->lim.limTimers.gLimHeartBeatTimer.pMac)
       {
           if(VOS_TRUE != tx_timer_running(&pMac->lim.limTimers.gLimHeartBeatTimer))
           {
               PELOGE(pmmLog(pMac, LOGE, FL("Unexpected heartbeat timer not running"));)
               limReactivateHeartBeatTimer(pMac, psessionEntry);
           }
       }
       respStatus = eSIR_SME_BMPS_REQ_REJECT;
       goto failure;
    }

    /* At this point, device is associated and PMM is not in BMPS_SLEEP state. 
     * Heartbeat timer not running is an indication that PE have detected a
     * loss of link. In this case, reject BMPS request. 
     */
     /* TODO : We need to have a better check. This check is not valid */
#if 0     
    if ( (pMac->sys.gSysEnableLinkMonitorMode) && (pMac->lim.limTimers.gLimHeartBeatTimer.pMac) )
    {
        if(VOS_TRUE != tx_timer_running(&pMac->lim.limTimers.gLimHeartBeatTimer)) 
        {
            PELOGE(pmmLog(pMac, LOGE, 
<<<<<<< HEAD
                FL("Reject BMPS_REQ because HeartBeatTimer is not running. "));)
=======
                FL("Reject BMPS_REQ because HeartBeatTimer is not running. \n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            respStatus = eSIR_SME_BMPS_REQ_FAILED;
            goto failure;
        }
    }
#endif

    //If the following function returns SUCCESS, then PMM will wait for an explicit
    //response message from softmac.

    //changing PMM state before posting message to HAL, as this is a synchronous call to HAL
    pMac->pmm.gPmmState = ePMM_STATE_BMPS_WT_INIT_RSP;
    if((retStatus = pmmSendInitPowerSaveMsg(pMac,psessionEntry)) != eSIR_SUCCESS)
    {
        PELOGE(pmmLog(pMac, LOGE, 
<<<<<<< HEAD
            FL("pmmBmps: Init Power Save Request Failed: Sending Response: %d"),
=======
            FL("pmmBmps: Init Power Save Request Failed: Sending Response: %d\n"), 
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            retStatus);)

        respStatus = eSIR_SME_BMPS_REQ_REJECT;
        pmmBmpsUpdateHalReqFailureCnt(pMac);
        goto failure;
    }
    //Update the powerSave sessionId
    pMac->pmm.sessionId = psessionEntry->peSessionId;
    return;

failure:

    // Change the state back to original state
    pMac->pmm.gPmmState =origState;
    limSendSmeRsp(pMac, eWNI_PMC_ENTER_BMPS_RSP, respStatus, 0, 0);
    return;
}


/**
 * pmmSendChangePowerSaveMsg()
 *
 *FUNCTION:
 * This function is called to send SIR_HAL_EXIT_BMPS_REQ to HAL.
 * This message will trigger HAL to program HW to wake up.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 * NA
 *
 *NOTE:
 * NA
 *
 * @param pMac  pointer to Global Mac structure.
 * @return success if message send is ok, else false.
 */
tSirRetStatus pmmSendChangePowerSaveMsg(tpAniSirGlobal pMac)
{
    tSirRetStatus  retStatus = eSIR_SUCCESS;
    tpExitBmpsParams  pExitBmpsParams;
    tSirMsgQ msgQ;
    tpPESession psessionEntry;
    tANI_U8  currentOperatingChannel = limGetCurrentOperatingChannel(pMac);

    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pExitBmpsParams, sizeof(*pExitBmpsParams)) )
    {
<<<<<<< HEAD
        pmmLog(pMac, LOGW, FL("palAllocateMemory() failed"));
=======
        pmmLog(pMac, LOGW, FL("palAllocateMemory() failed\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        retStatus = eSIR_MEM_ALLOC_FAILED;
        return retStatus;
    }

    if((psessionEntry = peGetValidPowerSaveSession(pMac)) == NULL )
    {
        retStatus = eSIR_FAILURE;
<<<<<<< HEAD
        palFreeMemory(pMac->hHdd, (tANI_U8*)pExitBmpsParams);
=======
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        return retStatus;
    }

    palZeroMemory( pMac->hHdd, (tANI_U8 *)pExitBmpsParams, sizeof(*pExitBmpsParams));
    msgQ.type = WDA_EXIT_BMPS_REQ;
    msgQ.reserved = 0;
    msgQ.bodyptr = pExitBmpsParams;
    msgQ.bodyval = 0;

    /* If reason for full power is disconnecting (ie. link is
     * disconnected) or becasue of channel switch or full power requested 
     * because of beacon miss and connected on DFS channel 
     * then we should not send data null.
     * For all other reason code, send data null.
     */
    if ( !(SIR_IS_FULL_POWER_REASON_DISCONNECTED(pMac->pmm.gPmmExitBmpsReasonCode) ||
          ( (eSME_MISSED_BEACON_IND_RCVD == pMac->pmm.gPmmExitBmpsReasonCode) && 
             limIsconnectedOnDFSChannel(currentOperatingChannel))))
        pExitBmpsParams->sendDataNull = 1;

    pExitBmpsParams->bssIdx = psessionEntry->bssIdx;
   
    /* we need to defer any incoming messages until we
     * get a WDA_EXIT_BMPS_RSP from HAL.
     */
    SET_LIM_PROCESS_DEFD_MESGS(pMac, false);
    MTRACE(macTraceMsgTx(pMac, NO_SESSION, msgQ.type));
    retStatus = wdaPostCtrlMsg( pMac, &msgQ);
    if( eSIR_SUCCESS != retStatus )
    {
<<<<<<< HEAD
        PELOGE(pmmLog( pMac, LOGE, FL("Sending WDA_EXIT_BMPS_REQ failed, reason=%X "), retStatus );)
=======
        PELOGE(pmmLog( pMac, LOGE, FL("Sending WDA_EXIT_BMPS_REQ failed, reason=%X \n"), retStatus );)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        palFreeMemory(pMac->hHdd, (tANI_U8*)pExitBmpsParams);
        return retStatus;
    }

<<<<<<< HEAD
    PELOG1(pmmLog(pMac, LOG1, FL("WDA_EXIT_BMPS_REQ has been successfully sent to HAL"));)
=======
    PELOG1(pmmLog(pMac, LOG1, FL("WDA_EXIT_BMPS_REQ has been successfully sent to HAL\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    return retStatus;
}


/**
 * pmmSendInitPowerSaveMsg()
 *
 *FUNCTION:
 * This function is called to send ENTER_BMPS_REQ message to HAL.
 * This message is sent to intialize the process of bringing the
 * station into power save state.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 * NA
 *
 *NOTE:
 * NA
 *
 * @param pMac  pointer to Global Mac structure.
 * @param mode The Power Save or Active State
 *
 * @return success if message send is ok, else false.
 */

tSirRetStatus  pmmSendInitPowerSaveMsg(tpAniSirGlobal pMac,tpPESession psessionEntry)
{
    tSirRetStatus   retCode = eSIR_SUCCESS;
    tSirMsgQ msgQ;
    tpEnterBmpsParams pBmpsParams = NULL;
<<<<<<< HEAD
    tANI_U8     i = 0;
=======
    int         i=0;

>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    tANI_U32    rssiFilterPeriod = 5;
    tANI_U32    numBeaconPerRssiAverage = 5;
    tANI_U32    bRssiFilterEnable = FALSE;

<<<<<<< HEAD
    if(psessionEntry->currentBssBeaconCnt == 0 )
    {
        PELOGE(pmmLog( pMac, LOGE,  FL("Beacon count is zero, can not retrieve the TSF, failing the Enter Bmps Request"));)
=======
    if(psessionEntry->currentBssBeaconCnt == 0)
    {
        PELOGE(pmmLog( pMac, LOGE,  FL("Beacon count is zero, can not retrieve the TSF, failing the Enter Bmps Request\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        return eSIR_FAILURE;
    }

    if (palAllocateMemory(pMac->hHdd, (void **)&pBmpsParams, sizeof(tEnterBmpsParams)) != eHAL_STATUS_SUCCESS)
    {
<<<<<<< HEAD
        pmmLog(pMac, LOGP, "PMM: Not able to allocate memory for Enter Bmps");
=======
        pmmLog(pMac, LOGP, "PMM: Not able to allocate memory for Enter Bmps\n");
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        return eSIR_FAILURE;
    }

    pMac->pmm.inMissedBeaconScenario = FALSE;
    pBmpsParams->respReqd = TRUE;

    pBmpsParams->tbtt = psessionEntry->lastBeaconTimeStamp;
    pBmpsParams->dtimCount = psessionEntry->lastBeaconDtimCount;
    pBmpsParams->dtimPeriod = psessionEntry->lastBeaconDtimPeriod;
    pBmpsParams->bssIdx = psessionEntry->bssIdx;

    if(wlan_cfgGetInt(pMac, WNI_CFG_RSSI_FILTER_PERIOD, &rssiFilterPeriod) != eSIR_SUCCESS)
        pmmLog(pMac, LOGP, FL("pmmCfg: cfgGet failed for Rssi filter period"));

<<<<<<< HEAD
    // This flag can be overwritten when 11r/CCXEnabled=1 or FastTransition=1
=======
    // This flag can be overridden when 11r/CCXEnabled=1 and FastTransition=1
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    if(wlan_cfgGetInt(pMac, WNI_CFG_PS_ENABLE_RSSI_MONITOR, &bRssiFilterEnable) != eSIR_SUCCESS)
        pmmLog(pMac, LOGP, FL("pmmCfg: cfgGet failed for Rssi monitor enable flag"));
    pBmpsParams->bRssiFilterEnable = bRssiFilterEnable;

<<<<<<< HEAD
#if  defined (WLAN_FEATURE_VOWIFI_11R) || defined (FEATURE_WLAN_CCX)
    // If there is a CCX assoc or 11r assoc we need to pick up the rssiFilterPeriod from the
    // FT config value.
    if (TRUE != pBmpsParams->bRssiFilterEnable)
    {
        for (i = 0; i < pMac->lim.maxBssId; i++)
        {
            if (limisFastTransitionRequired(pMac, i))
            {
                // We need to override the ini value to enable
                // FW RSSI Monitoring. Basically if CCX or FT are enabled
                // then enable FW RSSI Monitoring
                pBmpsParams->bRssiFilterEnable = TRUE;
                break;
            }
        }
    }
#endif

#ifdef FEATURE_WLAN_LFR
    /* if LFR is enabled, then enabled FW RSSI Monitoring */
    if (TRUE != pBmpsParams->bRssiFilterEnable)
    {
        for (i = 0; i < pMac->lim.maxBssId; i++)
        {
            if (limIsFastRoamEnabled(pMac, i))
            {
                pBmpsParams->bRssiFilterEnable = TRUE;
                break;
            }
=======

#if  defined (WLAN_FEATURE_VOWIFI_11R) || defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
    // If there is a CCX assoc or 11r assoc we need to pick up the rssiFilterPeriod from the
    // FT config value.
    for(i =0; i < pMac->lim.maxBssId; i++)
    {
        if (limisFastTransitionRequired(pMac, i))
        {
            if(wlan_cfgGetInt(pMac, WNI_CFG_FT_RSSI_FILTER_PERIOD, &rssiFilterPeriod) != eSIR_SUCCESS)
                pmmLog(pMac, LOGP, FL("pmmCfg: cfgGet failed for Rssi filter period"));
            // We need to override the ini value to enable 
            // FW RSSI Monitoring. Basically if CCX and FT are enabled
            // then enable FW RSSI Monitoring

            pBmpsParams->bRssiFilterEnable = TRUE;
            break;
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        }
    }
#endif

    pBmpsParams->rssiFilterPeriod = (tANI_U8)rssiFilterPeriod;

<<<<<<< HEAD
    /* The numBeaconPerRssiAverage should be less than the max allowed (default set to 20 in CFG)
=======
    /* The numBeaconPerRssiAverage should be <= rssiFilter Period,
     * and less than the max allowed (default set to 20 in CFG)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
     */
    if(wlan_cfgGetInt(pMac, WNI_CFG_NUM_BEACON_PER_RSSI_AVERAGE, &numBeaconPerRssiAverage) != eSIR_SUCCESS)
        pmmLog(pMac, LOGP, FL("pmmCfg: cfgGet failed for num beacon per rssi"));

<<<<<<< HEAD
    pBmpsParams->numBeaconPerRssiAverage =
            (tANI_U8)GET_MIN_VALUE((tANI_U8) numBeaconPerRssiAverage, WNI_CFG_NUM_BEACON_PER_RSSI_AVERAGE_STAMAX);

    pmmLog (pMac, LOG1,
        "%s: [INFOLOG]RssiFilterInfo..%d %x %x", __func__, (int)pBmpsParams->bRssiFilterEnable,
=======
    pBmpsParams->numBeaconPerRssiAverage = (tANI_U8) numBeaconPerRssiAverage;
    if (numBeaconPerRssiAverage > rssiFilterPeriod)
        pBmpsParams->numBeaconPerRssiAverage = 
            (tANI_U8)GET_MIN_VALUE(rssiFilterPeriod, WNI_CFG_NUM_BEACON_PER_RSSI_AVERAGE_STAMAX);

    pmmLog (pMac, LOG1,
        "%s: [INFOLOG]RssiFilterInfo..%d %x %x\n", __func__, (int)pBmpsParams->bRssiFilterEnable,
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        (unsigned int)pBmpsParams->rssiFilterPeriod, (unsigned int)pBmpsParams->numBeaconPerRssiAverage);

    msgQ.type = WDA_ENTER_BMPS_REQ;
    msgQ.reserved = 0;
    msgQ.bodyptr = pBmpsParams;
    msgQ.bodyval = 0;

    PELOG2(pmmLog( pMac, LOG2,
        FL( "pmmBmps: Sending WDA_ENTER_BMPS_REQ" ));)

    /* we need to defer any incoming messages until we get a
     * WDA_ENTER_BMPS_RSP from HAL.
     */
    SET_LIM_PROCESS_DEFD_MESGS(pMac, false);

    MTRACE(macTraceMsgTx(pMac, psessionEntry->peSessionId, msgQ.type));
    if( eSIR_SUCCESS != (retCode = wdaPostCtrlMsg( pMac, &msgQ )))
    {
        palFreeMemory(pMac->hHdd, pBmpsParams);
        PELOGE(pmmLog( pMac, LOGE,
<<<<<<< HEAD
            FL("Posting WDA_ENTER_BMPS_REQ to HAL failed, reason=%X"),
=======
            FL("Posting WDA_ENTER_BMPS_REQ to HAL failed, reason=%X\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            retCode );)
    }

    return retCode;
}

/**
 * pmmSendPowerSaveCfg()
 *
 *FUNCTION:
 * This function is called to send power save configurtion.
 *
 *NOTE:
 *
 * @param pMac  pointer to Global Mac structure.
 * @param mode The Power Save or Active State
 *
 * @return success if message send is ok, else false.
 */
tSirRetStatus pmmSendPowerSaveCfg(tpAniSirGlobal pMac, tpSirPowerSaveCfg pUpdatedPwrSaveCfg)
{
    tSirRetStatus   retCode = eSIR_SUCCESS;
    tSirMsgQ    msgQ;
    tANI_U32    listenInterval;
    tANI_U32    HeartBeatCount = 1;
    tANI_U32    maxPsPoll;
    tANI_U32    numBeaconPerRssiAverage;
    tANI_U32    minRssiThreshold;
    tANI_U32    nthBeaconFilter;
    tANI_U32    broadcastFrameFilter;
    tANI_U32    rssiFilterPeriod;
    tANI_U32    ignoreDtim;

    if (NULL == pUpdatedPwrSaveCfg)
        goto returnFailure;

    if(pMac->lim.gLimSmeState != eLIM_SME_IDLE_STATE  )
    {
        pmmLog(pMac, LOGE,
            FL("pmmCfg: Power Save Configuration received in invalid global sme state %d"),
            pMac->lim.gLimSmeState);
        retCode = eSIR_SME_INVALID_STATE;
        goto returnFailure;
    }

    // Get power save configuration CFG values
    if(wlan_cfgGetInt(pMac, WNI_CFG_LISTEN_INTERVAL, &listenInterval) != eSIR_SUCCESS)
        pmmLog(pMac, LOGP, FL("pmmCfg: cfgGet failed for listen interval"));
    pUpdatedPwrSaveCfg->listenInterval = (tANI_U16)listenInterval;

    if(wlan_cfgGetInt(pMac, WNI_CFG_HEART_BEAT_THRESHOLD, &HeartBeatCount) != eSIR_SUCCESS)
        pmmLog(pMac, LOGP, FL("pmmCfg: cfgGet failed for heart beat thresh"));

    pMac->lim.gLimHeartBeatCount = HeartBeatCount;
    pUpdatedPwrSaveCfg->HeartBeatCount = HeartBeatCount;

    if(wlan_cfgGetInt(pMac, WNI_CFG_NTH_BEACON_FILTER, &nthBeaconFilter) != eSIR_SUCCESS)
        pmmLog(pMac, LOGP, FL("pmmCfg: cfgGet failed for Nth beacon filter"));
    pUpdatedPwrSaveCfg->nthBeaconFilter = nthBeaconFilter;

    if(wlan_cfgGetInt(pMac, WNI_CFG_MAX_PS_POLL, &maxPsPoll) != eSIR_SUCCESS)
        pmmLog(pMac, LOGP, FL("pmmCfg: cfgGet failed for max poll"));
    pUpdatedPwrSaveCfg->maxPsPoll = maxPsPoll;

    if(wlan_cfgGetInt(pMac, WNI_CFG_MIN_RSSI_THRESHOLD, &minRssiThreshold) != eSIR_SUCCESS)
        pmmLog(pMac, LOGP, FL("pmmCfg: cfgGet failed for min RSSI Threshold"));
    pUpdatedPwrSaveCfg->minRssiThreshold = minRssiThreshold;

    if(wlan_cfgGetInt(pMac, WNI_CFG_NUM_BEACON_PER_RSSI_AVERAGE, &numBeaconPerRssiAverage) != eSIR_SUCCESS)
        pmmLog(pMac, LOGP, FL("pmmCfg: cfgGet failed for num beacon per rssi"));
    pUpdatedPwrSaveCfg->numBeaconPerRssiAverage = (tANI_U8) numBeaconPerRssiAverage;

    if(wlan_cfgGetInt(pMac, WNI_CFG_RSSI_FILTER_PERIOD, &rssiFilterPeriod) != eSIR_SUCCESS)
        pmmLog(pMac, LOGP, FL("pmmCfg: cfgGet failed for Rssi filter period"));
    pUpdatedPwrSaveCfg->rssiFilterPeriod = (tANI_U8) rssiFilterPeriod;

    if(wlan_cfgGetInt(pMac, WNI_CFG_BROADCAST_FRAME_FILTER_ENABLE, &broadcastFrameFilter) != eSIR_SUCCESS)
        pmmLog(pMac, LOGP, FL("pmmCfg: cfgGet failed for Nth beacon filter"));
    pUpdatedPwrSaveCfg->broadcastFrameFilter = (tANI_U8) broadcastFrameFilter;

    if(wlan_cfgGetInt(pMac, WNI_CFG_IGNORE_DTIM, &ignoreDtim) != eSIR_SUCCESS)
        pmmLog(pMac, LOGP, FL("pmmCfg: cfgGet failed for ignoreDtim"));
    pUpdatedPwrSaveCfg->ignoreDtim = (tANI_U8) ignoreDtim;

<<<<<<< HEAD
=======
    /* The numBeaconPerRssiAverage should be <= rssiFilter Period,
     * and less than the max allowed (default set to 20 in CFG)
     */
    if (numBeaconPerRssiAverage > rssiFilterPeriod)
        pUpdatedPwrSaveCfg->numBeaconPerRssiAverage = (tANI_U8)GET_MIN_VALUE(rssiFilterPeriod, WNI_CFG_NUM_BEACON_PER_RSSI_AVERAGE_STAMAX);

>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    //Save a copy of the CFG in global pmm context.
    palCopyMemory( pMac->hHdd, (tANI_U8 *) &pMac->pmm.gPmmCfg,  pUpdatedPwrSaveCfg, sizeof(tSirPowerSaveCfg));


    msgQ.type = WDA_PWR_SAVE_CFG;
    msgQ.reserved = 0;
    msgQ.bodyptr = pUpdatedPwrSaveCfg;
    msgQ.bodyval = 0;

    PELOG1(pmmLog( pMac, LOG1, FL( "pmmBmps: Sending WDA_PWR_SAVE_CFG to HAL"));)
    MTRACE(macTraceMsgTx(pMac, NO_SESSION, msgQ.type));
    if( eSIR_SUCCESS != (retCode = wdaPostCtrlMsg( pMac, &msgQ )))
    {
        pmmLog( pMac, LOGP,
            FL("Posting WDA_PWR_SAVE_CFG to HAL failed, reason=%X"),
            retCode );
        goto returnFailure;
    }
    return retCode;

returnFailure:

    /* In case of failure, we need to free the memory */
    if (NULL != pUpdatedPwrSaveCfg)
    {
        palFreeMemory( pMac->hHdd, (tANI_U8 *) pUpdatedPwrSaveCfg);
    }
    return retCode;
}

/**
 * pmmExitBmpsResponseHandler
 *
 *FUNCTION:
 * This function processes the Wakeup Rsp from HAL and if successfull,
 * sends a respnose back to PMC layer.
 *LOGIC:
 *
 *ASSUMPTIONS:
 * NA
 *
 *NOTE:
 * NA
 *
 * @param pMac  pointer to Global Mac structure.
 * @param rspStatus Status of the response, Success or an error code.
 *
 * @return none.
 */
void pmmExitBmpsResponseHandler(tpAniSirGlobal pMac,  tpSirMsgQ limMsg)
{
    tpExitBmpsParams  pExitBmpsRsp;
    eHalStatus  rspStatus;
    tANI_U8 PowersavesessionId;
    tpPESession psessionEntry;
    tSirResultCodes retStatus = eSIR_SME_SUCCESS;
    
    /* Copy the power save sessionId to the local variable */
    PowersavesessionId = pMac->pmm.sessionId;

    /* we need to process all the deferred messages enqueued since
     * the initiating the SIR_HAL_EXIT_BMPS_REQ.
     */

    SET_LIM_PROCESS_DEFD_MESGS(pMac, true);

    if((psessionEntry = peFindSessionBySessionId(pMac,PowersavesessionId))==NULL)
    {
<<<<<<< HEAD
        pmmLog(pMac, LOGP,FL("Session Does not exist for given sessionID"));
=======
        limLog(pMac, LOGP,FL("Session Does not exist for given sessionID\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        return;
    }

    

    /* Update wakeup statistics */
    pmmUpdateWakeupStats(pMac);

    if (NULL == limMsg->bodyptr)
    {
        pmmLog(pMac, LOGE, FL("Received SIR_HAL_EXIT_BMPS_RSP with NULL "));
        return;
    }
    pExitBmpsRsp = (tpExitBmpsParams)(limMsg->bodyptr);
    rspStatus = pExitBmpsRsp->status;

    if(pMac->pmm.gPmmState != ePMM_STATE_BMPS_WT_WAKEUP_RSP)
    {
        PELOGE(pmmLog(pMac, LOGE,
<<<<<<< HEAD
            FL("Received SIR_HAL_EXIT_BMPS_RSP while in incorrect state: %d"),
=======
            FL("Received SIR_HAL_EXIT_BMPS_RSP while in incorrect state: %d\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            pMac->pmm.gPmmState);)

        retStatus = eSIR_SME_INVALID_PMM_STATE;
        pmmBmpsUpdateInvalidStateCnt(pMac);
    }
    else
    {
<<<<<<< HEAD
        PELOGW(pmmLog(pMac, LOGW, FL("Received SIR_HAL_EXIT_BMPS_RSP in correct state. "));)
=======
        PELOGW(pmmLog(pMac, LOGW, FL("Received SIR_HAL_EXIT_BMPS_RSP in correct state. \n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    }

    /* PE is going to wakeup irrespective of whether
     * SIR_HAL_EXIT_BMPS_REQ was successful or not
     */
    switch (rspStatus)
    {
        case eHAL_STATUS_SUCCESS:
            retStatus = eSIR_SME_SUCCESS;
            break;

        default:
            {
                /* PE is going to be awake irrespective of whether EXIT_BMPS_REQ
                 * failed or not. This is mainly to eliminate the dead-lock condition
                 * But, PMC will be informed about the error.
                 */
                retStatus = eSIR_SME_BMPS_REQ_FAILED;
            }
            break;

    }

    pMac->pmm.gPmmState = ePMM_STATE_BMPS_WAKEUP;
    pmmUpdateWakeupStats(pMac);

    // turn on background scan
    pMac->sys.gSysEnableScanMode = true;

    // send response to PMC
<<<<<<< HEAD
   if(IS_FEATURE_SUPPORTED_BY_FW(SLM_SESSIONIZATION) )
=======
   if(IS_SLM_SESSIONIZATION_SUPPORTED_BY_FW )
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
   {
       limSendSmeRsp(pMac, eWNI_PMC_EXIT_BMPS_RSP, retStatus, 
                  psessionEntry->smeSessionId, psessionEntry->transactionId);
   }
   else
   {
       limSendSmeRsp(pMac, eWNI_PMC_EXIT_BMPS_RSP, retStatus, 0, 0);
   }

    if ( pMac->pmm.gPmmExitBmpsReasonCode == eSME_MISSED_BEACON_IND_RCVD)
    {
<<<<<<< HEAD
        PELOGW(pmmLog(pMac, LOGW, FL("Rcvd SIR_HAL_EXIT_BMPS_RSP with MISSED_BEACON"));)
=======
        PELOGW(pmmLog(pMac, LOGW, FL("Rcvd SIR_HAL_EXIT_BMPS_RSP with MISSED_BEACON\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        pmmMissedBeaconHandler(pMac);
    }
    else if(pMac->pmm.inMissedBeaconScenario)
    {
        PELOGW(pmmLog(pMac, LOGW, FL("Rcvd SIR_HAL_EXIT_BMPS_RSP in missed beacon scenario but reason code not correct"));)
        pmmMissedBeaconHandler(pMac);
    }
    else
    {
        // Enable heartbeat timer
        limReactivateHeartBeatTimer(pMac, psessionEntry);
    }
    return;
}


/**
 * pmmMissedBeaconHandler()
 *
 *FUNCTION:
 *  This function is called when PMM receives an eWNI_PMC_EXIT_BMPS_REQ
 *  with reason code being eSME_MISSED_BEACON_IND_RCVD.
 *
 *NOTE:
 * @param pMac  pointer to Global Mac structure.
 * @return none
 */
void pmmMissedBeaconHandler(tpAniSirGlobal pMac)
{
    tANI_U8 pwrSaveSessionId;
    tANI_U32 beaconInterval = 0;
    tANI_U32 heartBeatInterval = pMac->lim.gLimHeartBeatCount;
    tpPESession psessionEntry;
    
    /* Copy the power save sessionId to the local variable */
    pwrSaveSessionId = pMac->pmm.sessionId;

    if((psessionEntry = peFindSessionBySessionId(pMac,pwrSaveSessionId))==NULL)
    {
<<<<<<< HEAD
        pmmLog(pMac, LOGE,FL("Session Does not exist for given sessionID"));
=======
        limLog(pMac, LOGE,FL("Session Does not exist for given sessionID\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        return;
    }


<<<<<<< HEAD
    PELOGE(pmmLog(pMac, LOG1, FL("The device woke up due to MISSED BEACON "));)
=======
    PELOGE(pmmLog(pMac, LOG1, FL("The device woke up due to MISSED BEACON \n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

    /* Proceed only if HeartBeat timer is created */
    if((pMac->lim.limTimers.gLimHeartBeatTimer.pMac) &&
       (pMac->lim.gLimTimersCreated))
    {
        if (wlan_cfgGetInt(pMac, WNI_CFG_BEACON_INTERVAL, &beaconInterval) != eSIR_SUCCESS)
<<<<<<< HEAD
            PELOG1(pmmLog(pMac, LOG1, FL("Fail to get BEACON_INTERVAL value"));)
=======
            PELOG1(pmmLog(pMac, LOG1, FL("Fail to get BEACON_INTERVAL value\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

        /* Change timer to reactivate it in future */
        heartBeatInterval= SYS_MS_TO_TICKS(beaconInterval * heartBeatInterval);

        if( tx_timer_change(&pMac->lim.limTimers.gLimHeartBeatTimer,
                            (tANI_U32)heartBeatInterval, 0) != TX_SUCCESS)
        {
<<<<<<< HEAD
            PELOG1(pmmLog(pMac, LOG1, FL("Fail to change HeartBeat timer"));)
=======
            PELOG1(pmmLog(pMac, LOG1, FL("Fail to change HeartBeat timer\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        }

        /* update some statistics */
        if(LIM_IS_CONNECTION_ACTIVE(psessionEntry))
        {
            if(psessionEntry->LimRxedBeaconCntDuringHB < MAX_NO_BEACONS_PER_HEART_BEAT_INTERVAL)
                pMac->lim.gLimHeartBeatBeaconStats[psessionEntry->LimRxedBeaconCntDuringHB]++;
            else
                pMac->lim.gLimHeartBeatBeaconStats[0]++;
        }

        /* To handle the missed beacon failure, message is being posted to self as if the
         * actual timer has expired. This is done to make sure that there exists one
         * common entry and exit points
         */
        //limResetHBPktCount(pMac); // 090805: Where did this come from?
        limResetHBPktCount(psessionEntry); // 090805: This is what it SHOULD be.  If we even need it.
        pmmSendMessageToLim(pMac, SIR_LIM_HEART_BEAT_TIMEOUT);
    }
    else
    {
<<<<<<< HEAD
        PELOGE(pmmLog(pMac, LOGE, FL("HeartBeat Timer is not created, cannot re-activate"));)
=======
        PELOGE(pmmLog(pMac, LOGE, FL("HeartBeat Timer is not created, cannot re-activate\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    }

    return;
}


/**
 * pmmExitBmpsIndicationHandler
 *
 *FUNCTION:
 * This function sends a Power Save Indication. back to PMC layer.
 * This indication is originated from softmac and will occur in the following two
 * scenarios:
 * 1) When softmac is in sleep state and wakes up to parse TIM and finds that
 *     AP has the data pending for this STA, then it sends this indication to let PMC know
 *    that it is going to be awake and pass the control over to PMC
 * 2) When softmac is in sleep state and wakes up to parse TIM and determines that
 *     current TIM is DTIM and AP has buffered broadcast/multicast frames.
 *    In this scenario, softmac needs to remain awake for broadcast/multicast frames and it
 *    sends an indication to PMC that it is awake and passes the control over to PMC.
 * 3) If station is awake and 'fEnablePwrSaveImmediately' flag is set, then softmac will transmit all
 *     frames in its queues and go to sleep. Before going to sleep it sends the notification to PMC that
 *     it is going to sleep.
 *LOGIC:
 *
 *ASSUMPTIONS:
 * NA
 *
 *NOTE:
 * NA
 *
 * @param pMac  pointer to Global Mac structure.
 * @param rspStatus Status of the response, Success or an error code.
 *
 * @return none.
 */

void pmmExitBmpsIndicationHandler(tpAniSirGlobal pMac, tANI_U8 mode, eHalStatus rspStatus)
{

    tANI_U32 beaconInterval = 0;
    tANI_U32 heartBeatInterval = pMac->lim.gLimHeartBeatCount;
    tANI_U8  powersavesessionId;
    tpPESession psessionEntry;

    /* Copy the power save sessionId to the local variable */
    powersavesessionId = pMac->pmm.sessionId;

    psessionEntry = peFindSessionBySessionId(pMac,powersavesessionId);

    if(psessionEntry == NULL)
    {
<<<<<<< HEAD
      PELOGE(pmmLog(pMac, LOGE,
             FL("Session does Not exist with given sessionId :%d "),powersavesessionId);)
=======
      PELOGE(limLog(pMac, LOGE,FL("Session does Not exist with given sessionId :%d \n"),powersavesessionId);)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
      return;
    }

    /* Since, the hardware is already wokenup, PE also wakesup and informs
     * the upper layers that the system is waking up. Hence always Success is
     * sent in the reason code for the message sent to PMC
     */

    PELOGW(pmmLog(pMac, LOGW, 
<<<<<<< HEAD
           FL("pmmBmps: Received SIR_HAL_EXIT_BMPS_IND from HAL, Exiting BMPS sleep mode")); )
=======
           FL("pmmBmps: Received SIR_HAL_EXIT_BMPS_IND from HAL, Exiting BMPS sleep mode\n")); )
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838


    pMac->pmm.gPmmState = ePMM_STATE_BMPS_WAKEUP;
    pmmUpdateWakeupStats(pMac);

    /* turn on background scan */
    pMac->sys.gSysEnableScanMode = true;

    pmmBmpsUpdateWakeupIndCnt(pMac);

    /* Inform SME about the system awake state */
    limSendSmeRsp(pMac,
                  eWNI_PMC_EXIT_BMPS_IND,
                  eSIR_SME_SUCCESS, 0, 0);

    switch(rspStatus)
    {

        /* The SoftMAC sends wakeup indication even when Heart-Beat timer expired
         * The PE should start taking action against this as soon as it identifies
         * that the SoftMAC has identified heart-beat miss
         */
        case eHAL_STATUS_HEARTBEAT_TMOUT:
            {
                PELOG1(pmmLog(pMac, LOG1,
<<<<<<< HEAD
                              FL("pmmBmps: The device woke up due to HeartBeat Timeout"));)
=======
                              FL("pmmBmps: The device woke up due to HeartBeat Timeout\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

                /* Proceed only if HeartBeat timer is created */
                if((pMac->lim.limTimers.gLimHeartBeatTimer.pMac) &&
                   (pMac->lim.gLimTimersCreated))
                {

                    /* Read the beacon interval from sessionTable */
                    beaconInterval = psessionEntry->beaconParams.beaconInterval;

                    /* Change timer to reactivate it in future */
                    heartBeatInterval= SYS_MS_TO_TICKS(beaconInterval * heartBeatInterval);

                    if(tx_timer_change(&pMac->lim.limTimers.gLimHeartBeatTimer,
                                       (tANI_U32)heartBeatInterval, 0) != TX_SUCCESS)
                    {
                        PELOG1(pmmLog(pMac, LOG1,
<<<<<<< HEAD
                               FL("pmmBmps: Unable to change HeartBeat timer"));)
=======
                               FL("pmmBmps: Unable to change HeartBeat timer\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                    }

                    /* update some statistics */
                    if(LIM_IS_CONNECTION_ACTIVE(psessionEntry))
                    {
                        if(psessionEntry->LimRxedBeaconCntDuringHB < MAX_NO_BEACONS_PER_HEART_BEAT_INTERVAL)
                            pMac->lim.gLimHeartBeatBeaconStats[psessionEntry->LimRxedBeaconCntDuringHB]++;
                        else
                            pMac->lim.gLimHeartBeatBeaconStats[0]++;
                    }

                    /* To handle the heartbeat failure, message is being posted to self as if the
                     * actual timer has expired. This is done to make sure that there exists one
                     * common entry and exit points
                     */
                    pmmSendMessageToLim(pMac, SIR_LIM_HEART_BEAT_TIMEOUT);

                }
                else
                {

                    PELOGE(pmmLog(pMac, LOGE, 
<<<<<<< HEAD
                           FL("pmmBmps: HeartBeat Timer is not created, cannot re-activate"));)
=======
                           FL("pmmBmps: HeartBeat Timer is not created, cannot re-activate\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                }
            }
            break;

        case eHAL_STATUS_NTH_BEACON_DELIVERY:
            break;

        default:
            break;

    }

    return;

}


// --------------------------------------------------------------------
/**
<<<<<<< HEAD
=======
 * pmmProcessMessageQueue
 *
 * FUNCTION:
 *
 * LOGIC:
 *
 * ASSUMPTIONS:
 *
 * NOTE:
 *
 * @param None
 * @return None
 */

void pmmProcessMessageQueue(tpAniSirGlobal pMac)
{
#if 0
    tSirMsgQ msg;

    while (1)
    {
        if (tx_queue_receive(&pMac->sys.gSirPmmMsgQ, (void *) &msg, TX_WAIT_FOREVER)
            != TX_SUCCESS)
            break;

        pmmProcessMessage(pMac, &msg);
    }
#endif
}

// --------------------------------------------------------------------
/**
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
 * pmmProcessMessage
 *
 * FUNCTION:  Processes the next received Power Management message
 *
 * LOGIC:
 *
 * ASSUMPTIONS:
 *
 * NOTE:
 *
 * @param None
 * @return None
 */

void pmmProcessMessage(tpAniSirGlobal pMac, tpSirMsgQ pMsg)
{
    switch (pMsg->type)
    {
        case eWNI_PMC_PWR_SAVE_CFG:
        {
            tpSirPowerSaveCfg pPSCfg;
            tSirMbMsg *pMbMsg = (tSirMbMsg *)pMsg->bodyptr;

            if (palAllocateMemory(pMac->hHdd, (void **)&pPSCfg, sizeof(tSirPowerSaveCfg)) != eHAL_STATUS_SUCCESS)
            {
<<<<<<< HEAD
                pmmLog(pMac, LOGP, "PMM: Not able to allocate memory for PMC Config");
            }
            (void) palCopyMemory(pMac->hHdd, pPSCfg, pMbMsg->data, sizeof(tSirPowerSaveCfg));
            (void) pmmSendPowerSaveCfg(pMac, pPSCfg);
=======
                pmmLog(pMac, LOGP, "PMM: Not able to allocate memory for PMC Config\n");
            }
            (void) palCopyMemory(pMac->hHdd, pPSCfg, pMbMsg->data, sizeof(tSirPowerSaveCfg));
            (void) pmmSendPowerSaveCfg(pMac, pPSCfg);

            // sending beacon filtering information down to HAL
            if (limSendBeaconFilterInfo(pMac) != eSIR_SUCCESS)
                pmmLog(pMac, LOGE, FL("Fail to send Beacon Filter Info \n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        }
            break;

        case eWNI_PMC_ENTER_BMPS_REQ:
            pmmInitBmpsPwrSave(pMac);
            break;

        case WDA_ENTER_BMPS_RSP:
<<<<<<< HEAD
            pmmInitBmpsResponseHandler(pMac, pMsg);
=======
            pmmInitBmpsResponseHandler(pMac, (eHalStatus)pMsg->bodyval);
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            break;

        case eWNI_PMC_EXIT_BMPS_REQ:
        {
            tpExitBmpsInfo  pExitBmpsInfo;
            tSirMbMsg      *pMbMsg = (tSirMbMsg *)pMsg->bodyptr;

            if (palAllocateMemory(pMac->hHdd, (void **)&pExitBmpsInfo, sizeof(tExitBmpsInfo)) != eHAL_STATUS_SUCCESS)
            {
<<<<<<< HEAD
                pmmLog(pMac, LOGP, "PMM: Failed to allocate memory for Exit BMPS Info ");
=======
                pmmLog(pMac, LOGP, "PMM: Failed to allocate memory for Exit BMPS Info \n");
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            }
            (void) palCopyMemory(pMac->hHdd, pExitBmpsInfo, pMbMsg->data, sizeof(tExitBmpsInfo));
            (void) pmmExitBmpsRequestHandler(pMac, pExitBmpsInfo);
        }
            break;

        case WDA_EXIT_BMPS_RSP:
            pmmExitBmpsResponseHandler(pMac, pMsg);
            break;

        case WDA_EXIT_BMPS_IND:
            pmmExitBmpsIndicationHandler(pMac, SIR_PM_ACTIVE_MODE, (eHalStatus)pMsg->bodyval);
            break;

        case eWNI_PMC_ENTER_IMPS_REQ:
            pmmEnterImpsRequestHandler(pMac);
            break;

        case WDA_ENTER_IMPS_RSP:
            pmmEnterImpsResponseHandler(pMac, (eHalStatus)pMsg->bodyval);
            break;

        case eWNI_PMC_EXIT_IMPS_REQ:
            pmmExitImpsRequestHandler(pMac);
            break;

        case WDA_EXIT_IMPS_RSP:
            pmmExitImpsResponseHandler(pMac, (eHalStatus)pMsg->bodyval);
            break;

        case eWNI_PMC_ENTER_UAPSD_REQ:
            pmmEnterUapsdRequestHandler(pMac);
            break;

        case WDA_ENTER_UAPSD_RSP:
            pmmEnterUapsdResponseHandler(pMac, pMsg);
            break;

        case eWNI_PMC_EXIT_UAPSD_REQ:
            pmmExitUapsdRequestHandler(pMac);
            break;

        case WDA_EXIT_UAPSD_RSP:
<<<<<<< HEAD
            pmmExitUapsdResponseHandler(pMac, pMsg);
=======
            pmmExitUapsdResponseHandler(pMac, (eHalStatus)pMsg->bodyval);
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            break;

        case eWNI_PMC_WOWL_ADD_BCAST_PTRN:
            pmmSendWowlAddBcastPtrn(pMac, pMsg);
            break;

        case eWNI_PMC_WOWL_DEL_BCAST_PTRN:
            pmmSendWowlDelBcastPtrn(pMac, pMsg);
            break;

        case eWNI_PMC_ENTER_WOWL_REQ:
            pmmEnterWowlRequestHandler(pMac, pMsg);
            break;

        case WDA_WOWL_ENTER_RSP:
            pmmEnterWowlanResponseHandler(pMac, pMsg);
            break;

        case eWNI_PMC_EXIT_WOWL_REQ:
            pmmExitWowlanRequestHandler(pMac);
            break;

        case WDA_WOWL_EXIT_RSP:
<<<<<<< HEAD
            pmmExitWowlanResponseHandler(pMac, pMsg);
=======
            pmmExitWowlanResponseHandler(pMac, (eHalStatus)pMsg->bodyval);
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            break;
#ifdef WLAN_FEATURE_PACKET_FILTERING
        case WDA_PACKET_COALESCING_FILTER_MATCH_COUNT_RSP:
            pmmFilterMatchCountResponseHandler(pMac, pMsg);
            break;
#endif // WLAN_FEATURE_PACKET_FILTERING


#ifdef WLAN_FEATURE_GTK_OFFLOAD
        case WDA_GTK_OFFLOAD_GETINFO_RSP:
            pmmGTKOffloadGetInfoResponseHandler(pMac, pMsg);
            break;
#endif // WLAN_FEATURE_GTK_OFFLOAD

        default:
            PELOGW(pmmLog(pMac, LOGW, 
<<<<<<< HEAD
                FL("PMM: Unknown message in pmmMsgQ type %d, potential memory leak!!"),
=======
                FL("PMM: Unknown message in pmmMsgQ type %d, potential memory leak!!\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                pMsg->type);)
    }

    if (NULL != pMsg->bodyptr)
    {
        palFreeMemory(pMac->hHdd, (tANI_U8 *)pMsg->bodyptr);
        pMsg->bodyptr = NULL;
    }
}






// --------------------------------------------------------------------
/**
 * pmmPostMessage
 *
 * FUNCTION:
 * Post a message to the pmm message queue
 *
 * LOGIC:
 *
 * ASSUMPTIONS:
 *
 * NOTE:
 *
 * @param pMsg pointer to message
 * @return None
 */

tSirRetStatus
pmmPostMessage(tpAniSirGlobal pMac, tpSirMsgQ pMsg)
{
<<<<<<< HEAD
=======
#if defined(VOSS_ENABLED)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    VOS_STATUS vosStatus;
    vosStatus = vos_mq_post_message(VOS_MQ_ID_PE, (vos_msg_t *) pMsg);
    if(!VOS_IS_STATUS_SUCCESS(vosStatus))
    {
<<<<<<< HEAD
        pmmLog(pMac, LOGP, FL("vos_mq_post_message failed with status code %d"), vosStatus);
        return eSIR_FAILURE;
    }
=======
        pmmLog(pMac, LOGP, FL("vos_mq_post_message failed with status code %d\n"), vosStatus);
        return eSIR_FAILURE;
    }
#elif defined(ANI_OS_TYPE_WINDOWS)
    pmmProcessMessage(pMac, pMsg);
#else
    if (tx_queue_send(&pMac->sys.gSirPmmMsgQ, pMsg, TX_NO_WAIT) != TX_SUCCESS)
        return eSIR_FAILURE;

#endif // VOSS_ENABLED
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

    return eSIR_SUCCESS;
}





/**
 * pmmUpdatePwrSaveStats
 *
 * FUNCTION:  updated BMPS stats, when Station is going into power save state.
 *
 * LOGIC:
 *
 * ASSUMPTIONS:
 *
 * NOTE:
 *
 * @param pMac pointer to Global MAC Structure.
 * @return None
 */

void pmmUpdatePwrSaveStats(tpAniSirGlobal pMac)
{
/*
    tANI_U64 TimeAwake = 0;

    pMac->pmm.BmpsSleepTimeStamp = vos_timer_get_system_ticks();

    if (pMac->pmm.BmpsWakeupTimeStamp)
        TimeAwake = (pMac->pmm.BmpsSleepTimeStamp - pMac->pmm.BmpsWakeupTimeStamp) /10;
    else
        TimeAwake = 0; // very first time

    if (TimeAwake > pMac->pmm.BmpsmaxTimeAwake)
    {
        pMac->pmm.BmpsmaxTimeAwake = TimeAwake;
    }

    if ((!pMac->pmm.BmpsminTimeAwake) || (TimeAwake < pMac->pmm.BmpsminTimeAwake))
    {
        pMac->pmm.BmpsminTimeAwake = TimeAwake;
    }

    pMac->pmm.BmpsavgTimeAwake = ( ( (pMac->pmm.BmpsavgTimeAwake * pMac->pmm.BmpscntSleep) + TimeAwake ) / (pMac->pmm.BmpscntSleep + 1) );

    pMac->pmm.BmpscntSleep++;
    return;
*/
}




/**
 * pmmUpdatePwrSaveStats
 *
 * FUNCTION:  updated BMPS stats, when Station is waking up.
 *
 * LOGIC:
 *
 * ASSUMPTIONS:
 *
 * NOTE:
 *
 * @param pMac pointer to Global MAC Structure.
 * @return None
 */

void pmmUpdateWakeupStats(tpAniSirGlobal pMac)
{
/*

        tANI_U64 SleepTime = 0;

        pMac->pmm.BmpsWakeupTimeStamp = vos_timer_get_system_ticks();
        SleepTime = (pMac->pmm.BmpsWakeupTimeStamp - pMac->pmm.BmpsSleepTimeStamp) / 10;

        if (SleepTime > pMac->pmm.BmpsmaxSleepTime)
        {
            pMac->pmm.BmpsmaxSleepTime = SleepTime;
        }

        if ((!pMac->pmm.BmpsminSleepTime) || (SleepTime < pMac->pmm.BmpsminSleepTime))
        {
            pMac->pmm.BmpsminSleepTime = SleepTime;
        }

        pMac->pmm.BmpsavgSleepTime = ( ( (pMac->pmm.BmpsavgSleepTime * pMac->pmm.BmpscntAwake) + SleepTime ) / (pMac->pmm.BmpscntAwake + 1) );

        pMac->pmm.BmpscntAwake++;
        return;
*/
}

// --------------------------------------------------------------------
/**
 * pmmEnterImpsRequestHandler
 *
 * FUNCTION:
 * This function sends the idle mode power save request from host device
 * drive to HAL. This function is called from pmmProcessMsg()
 *
 * LOGIC:
 *
 * ASSUMPTIONS:
 * None
 *
 * NOTE:
 *
 * @param   Global handle to MAC
 * @return  None
 */
void pmmEnterImpsRequestHandler (tpAniSirGlobal pMac)
{

    tSirResultCodes resultCode = eSIR_SME_SUCCESS;
    tSirRetStatus   retStatus = eSIR_SUCCESS;
    tPmmState       origState = pMac->pmm.gPmmState;

#ifdef FEATURE_WLAN_DIAG_SUPPORT 
    limDiagEventReport(pMac, WLAN_PE_DIAG_ENTER_IMPS_REQ_EVENT, peGetValidPowerSaveSession(pMac), 0, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT

    /*Returns True even single active session present */
    if(peIsAnySessionActive(pMac))
    {
        resultCode = eSIR_SME_INVALID_STATE;
        goto failure;
    }

    if ( ((pMac->pmm.gPmmState != ePMM_STATE_READY) &&
          (pMac->pmm.gPmmState != ePMM_STATE_IMPS_WAKEUP)) ||
         ((pMac->lim.gLimSmeState != eLIM_SME_IDLE_STATE) &&
          (pMac->lim.gLimSmeState != eLIM_SME_JOIN_FAILURE_STATE)) ||
         (pMac->lim.gLimMlmState != eLIM_MLM_IDLE_STATE) ||
         limIsChanSwitchRunning (pMac) ||
         limIsInQuietDuration (pMac) )
    {
        PELOGE(pmmLog(pMac, LOGE, 
<<<<<<< HEAD
              FL("pmmImps: PMM State = %d, Global MLM State = %d, Global SME State = %d, rejecting the sleep mode request"),
=======
              FL("pmmImps: PMM State = %d, Global MLM State = %d, Global SME State = %d, rejecting the sleep mode request\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
              pMac->pmm.gPmmState, pMac->lim.gLimMlmState, pMac->lim.gLimSmeState);)

        resultCode = eSIR_SME_INVALID_PMM_STATE;
        pmmImpsUpdateErrStateStats(pMac);
        goto failure;
    }

    // change PE state and send the request to HAL
    pMac->pmm.gPmmState = ePMM_STATE_IMPS_WT_SLEEP_RSP;
    if( (retStatus = pmmImpsSendChangePwrSaveMsg(pMac, SIR_PM_SLEEP_MODE)) != eSIR_SUCCESS)
    {
        PELOGE(pmmLog(pMac, LOGE, 
<<<<<<< HEAD
               FL("pmmImps: IMPS Sleep Request failed: sending response: %x"), retStatus);)
=======
               FL("pmmImps: IMPS Sleep Request failed: sending response: %x\n"), retStatus);)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

        resultCode = eSIR_SME_IMPS_REQ_FAILED;
        goto failure;
    }
    else
    {
        PELOG1(pmmLog(pMac, LOG1,
<<<<<<< HEAD
               FL("pmmImps: Waiting for SoftMac response for IMPS request"));)
=======
               FL("pmmImps: Waiting for SoftMac response for IMPS request\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    }
    return;

failure:
    pMac->pmm.gPmmState = origState;
    pmmImpsUpdateSleepErrStats(pMac, retStatus);

    limSendSmeRsp(pMac,
                  eWNI_PMC_ENTER_IMPS_RSP,
                  resultCode, 0, 0);

}

// --------------------------------------------------------------------
/**
 * pmmEnterImpsResponseHandler
 *
 * FUNCTION:
 * This function receives the response from HAL layer for the idle mode
 * power save request sent. The function is also responsible for checking
 * the correctness of the system state before configuring the new state
 * on success. This function is called by pmmProcessMsg()
 *
 * LOGIC:
 *
 * ASSUMPTIONS:
 * None
 *
 * NOTE:
 *
 * @param   Global handle to MAC, Status code
 * @return  None
 */
void pmmEnterImpsResponseHandler (tpAniSirGlobal pMac, eHalStatus rspStatus)
{
    tPmmState nextState = pMac->pmm.gPmmState;
    tSirResultCodes resultCode = eSIR_SME_SUCCESS;

    /* we need to process all the deferred messages enqueued since
     * the initiating the WDA_ENTER_IMPS_REQ.
     */
    SET_LIM_PROCESS_DEFD_MESGS(pMac, true);

    if(pMac->pmm.gPmmState != ePMM_STATE_IMPS_WT_SLEEP_RSP)
    {
        PELOGE(pmmLog(pMac, LOGE, 
<<<<<<< HEAD
               FL("pmmImps: Receives IMPS sleep rsp in invalid state: %d"),
=======
               FL("pmmImps: Receives IMPS sleep rsp in invalid state: %d\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
               pMac->pmm.gPmmState);)

        resultCode = eSIR_SME_INVALID_PMM_STATE;
        pmmImpsUpdateErrStateStats(pMac);

        goto failure;
    }

    if(eHAL_STATUS_SUCCESS == rspStatus)
    {
        //if success, change the state to IMPS sleep mode
        pMac->pmm.gPmmState = ePMM_STATE_IMPS_SLEEP;

        PELOG2(pmmLog(pMac, LOG2,
<<<<<<< HEAD
            FL("pmmImps: Received successful WDA_ENTER_IMPS_RSP from HAL"));)
=======
            FL("pmmImps: Received successful WDA_ENTER_IMPS_RSP from HAL\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

        //update power save statistics
        pmmImpsUpdatePwrSaveStats(pMac);

        limSendSmeRsp(pMac,
                      eWNI_PMC_ENTER_IMPS_RSP,
                      resultCode, 0, 0);
    }
    else
    {
        // go back to previous state if request failed
        nextState = ePMM_STATE_IMPS_WAKEUP;
        resultCode = eSIR_SME_CANNOT_ENTER_IMPS;
        goto failure;
    }
    return;

failure:
    PELOGE(pmmLog(pMac, LOGE, 
<<<<<<< HEAD
           FL("pmmImpsSleepRsp failed, Ret Code: %d, next state will be: %d"),
=======
           FL("pmmImpsSleepRsp failed, Ret Code: %d, next state will be: %d\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
           rspStatus,
           pMac->pmm.gPmmState);)

    pMac->pmm.gPmmState = nextState;

    limSendSmeRsp(pMac,
                  eWNI_PMC_ENTER_IMPS_RSP,
                  resultCode, 0, 0);
}


// --------------------------------------------------------------------
/**
 * pmmExitImpsRequestHandler
 *
 * FUNCTION:
 * This function is called by pmmProcessMsg(). The function sends a request
 * to HAL to wakeup the device from idle mode power save mode.
 *
 * LOGIC:
 *
 * ASSUMPTIONS:
 * None
 *
 * NOTE:
 *
 * @param   Global handle to MAC
 * @return  None
 */
void pmmExitImpsRequestHandler (tpAniSirGlobal pMac)
{
    tSirRetStatus retStatus = eSIR_SUCCESS;
    tSirResultCodes resultCode = eSIR_SME_SUCCESS;

    tPmmState origState = pMac->pmm.gPmmState;

#ifdef FEATURE_WLAN_DIAG_SUPPORT 
    limDiagEventReport(pMac, WLAN_PE_DIAG_EXIT_IMPS_REQ_EVENT, peGetValidPowerSaveSession(pMac), 0, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT

    if (ePMM_STATE_IMPS_SLEEP == pMac->pmm.gPmmState)
    {
        pMac->pmm.gPmmState = ePMM_STATE_IMPS_WT_WAKEUP_RSP;
        if( (retStatus = pmmImpsSendChangePwrSaveMsg(pMac, SIR_PM_ACTIVE_MODE)) !=
            eSIR_SUCCESS)
        {
            PELOGE(pmmLog(pMac, LOGE, 
<<<<<<< HEAD
                   FL("pmmImps: Wakeup request message sent to SoftMac failed"));)
=======
                   FL("pmmImps: Wakeup request message sent to SoftMac failed\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            resultCode = eSIR_SME_IMPS_REQ_FAILED;
            goto failure;
        }
    }
    else
    {
        // PE in invalid state 
        PELOGE(pmmLog(pMac, LOGE, 
<<<<<<< HEAD
                      FL("pmmImps: Wakeup Req received in invalid state: %x"),
=======
                      FL("pmmImps: Wakeup Req received in invalid state: %x\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                      pMac->pmm.gPmmState);)

        resultCode = eSIR_SME_INVALID_PMM_STATE;
        pmmImpsUpdateErrStateStats(pMac);

        goto failure;
    }
    return;

failure:
    PELOGE(pmmLog (pMac, LOGE, 
<<<<<<< HEAD
                   FL("pmmImps: Changing to IMPS wakeup mode failed, Ret Code: %d, Next State: %d"),
=======
                   FL("pmmImps: Changing to IMPS wakeup mode failed, Ret Code: %d, Next State: %d\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                   retStatus, pMac->pmm.gPmmState);)

    pMac->pmm.gPmmState = origState;
    pmmImpsUpdateWakeupErrStats(pMac, retStatus);

    limSendSmeRsp(pMac,
                  eWNI_PMC_EXIT_IMPS_RSP,
                  resultCode, 0, 0);
}


// --------------------------------------------------------------------
/**
 * pmmExitImpsResponseHandler
 *
 * FUNCTION:
 * This function receives the response from HAL layer for the idle mode
 * power save request sent. The function is also responsible for checking
 * the correctness of the system state before configuring the new state
 * on success. This function is called by pmmProcessMsg()
 *
 * LOGIC:
 *
 * ASSUMPTIONS:
 * None
 *
 * NOTE:
 *
 * @param  Global handle to MAC
 * @return None
 */
void pmmExitImpsResponseHandler(tpAniSirGlobal pMac, eHalStatus rspStatus)
{
    tSirResultCodes resultCode = eSIR_SME_SUCCESS;

    /* we need to process all the deferred messages enqueued since
     * the initiating the WDA_EXIT_IMPS_REQ.
     */
    SET_LIM_PROCESS_DEFD_MESGS(pMac, true);

    if (pMac->pmm.gPmmState != ePMM_STATE_IMPS_WT_WAKEUP_RSP)
    {
        PELOGE(pmmLog(pMac, LOGE, 
<<<<<<< HEAD
                      FL("pmmImps: Received 'Wakeup' response in invalid state: %d"),
=======
                      FL("pmmImps: Received 'Wakeup' response in invalid state: %d\n"), 
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                      pMac->pmm.gPmmState);)

        resultCode = eSIR_SME_INVALID_PMM_STATE;
        pmmImpsUpdateErrStateStats(pMac);
    }

    switch(rspStatus)
    {
    case eHAL_STATUS_SUCCESS:
        {
            resultCode = eSIR_SME_SUCCESS;
            PELOG2(pmmLog(pMac, LOG2, 
<<<<<<< HEAD
                          FL("pmmImps: Received WDA_EXIT_IMPS_RSP with Successful response from HAL"));)
=======
                          FL("pmmImps: Received WDA_EXIT_IMPS_RSP with Successful response from HAL\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        }
        break;

        default:
            {
                resultCode = eSIR_SME_IMPS_REQ_FAILED;
                PELOGW(pmmLog(pMac, LOGW, 
<<<<<<< HEAD
                              FL("pmmImps: Received WDA_EXIT_IMPS_RSP with Failure Status from HAL"));)
=======
                              FL("pmmImps: Received WDA_EXIT_IMPS_RSP with Failure Status from HAL\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            }
            break;

    }

    pMac->pmm.gPmmState = ePMM_STATE_IMPS_WAKEUP;

    //update power save statistics
    pmmImpsUpdateWakeupStats(pMac);

    limSendSmeRsp(pMac,
                  eWNI_PMC_EXIT_IMPS_RSP,
                  resultCode, 0, 0);
    return;

}

// --------------------------------------------------------------------
/**
 * pmmEnterUapsdRequestHandler
 *
 * FUNCTION:
 * This function process the eWNI_PMC_ENTER_UAPSD_REQ from PMC,
 * checks the correctness of the system state before configuring
 * PMM to the new ePMM_STATE_UAPSD_WT_SLEEP_RSP state, and invokes
 * invokes pmmUapsdSendChangePwrSaveMsg() to send
 * WDA_ENTER_UAPSD_REQ to HAL.
 *
 * NOTE:
 *
 * @param       Global handle to MAC
 * @return      None
 */
void pmmEnterUapsdRequestHandler (tpAniSirGlobal pMac)
{
    tSirResultCodes resultCode = eSIR_SME_SUCCESS;
    tSirRetStatus   retStatus = eSIR_SUCCESS;

    tPmmState origState = pMac->pmm.gPmmState;

#ifdef FEATURE_WLAN_DIAG_SUPPORT 
    limDiagEventReport(pMac, WLAN_PE_DIAG_ENTER_UAPSD_REQ_EVENT, peGetValidPowerSaveSession(pMac), 0, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT

    if ( (pMac->pmm.gPmmState != ePMM_STATE_BMPS_SLEEP) ||
         limIsSystemInScanState(pMac) )
    {
        PELOGE(pmmLog(pMac, LOGE,
<<<<<<< HEAD
            FL("pmmUapsd: PMM State = %d, Global MLM State = %d, Global SME State = %d, rejecting the sleep mode request"),
=======
            FL("pmmUapsd: PMM State = %d, Global MLM State = %d, Global SME State = %d, rejecting the sleep mode request\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            pMac->pmm.gPmmState, pMac->lim.gLimMlmState, pMac->lim.gLimSmeState);)

        resultCode = eSIR_SME_INVALID_PMM_STATE;
        goto failure;
    }

    pMac->pmm.gPmmState = ePMM_STATE_UAPSD_WT_SLEEP_RSP;

    if( (retStatus = pmmUapsdSendChangePwrSaveMsg(pMac, SIR_PM_SLEEP_MODE)) != eSIR_SUCCESS)
    {
        PELOGE(pmmLog(pMac, LOGE,
<<<<<<< HEAD
            FL("pmmUapsd: HAL_ENTER_UAPSD_REQ failed with response: %x"), retStatus);)
=======
            FL("pmmUapsd: HAL_ENTER_UAPSD_REQ failed with response: %x\n"), retStatus);)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        resultCode = eSIR_SME_UAPSD_REQ_FAILED;
        goto failure;
    }

<<<<<<< HEAD
    PELOG1(pmmLog(pMac, LOG1, FL("pmmUapsd: Waiting for WDA_ENTER_UAPSD_RSP "));)
=======
    PELOG1(pmmLog(pMac, LOG1, FL("pmmUapsd: Waiting for WDA_ENTER_UAPSD_RSP \n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    return;

failure:
    pMac->pmm.gPmmState = origState;
    limSendSmeRsp(pMac, eWNI_PMC_ENTER_UAPSD_RSP, resultCode, 0, 0);
    return;
}


// --------------------------------------------------------------------
/**
 * pmmEnterUapsdResponseHandler
 *
 * FUNCTION:
 * This function processes the SIR_HAL_ENTER_UAPSD_RSP from HAL.
 * If the response is successful, it puts PMM into ePMM_STATE_UAPSD_SLEEP
 * state and sends back success response to PMC.
 *
 * NOTE:
 *
 * @param  limMsg
 * @return None
 */
void pmmEnterUapsdResponseHandler(tpAniSirGlobal pMac, tpSirMsgQ limMsg)
{
    tpUapsdParams    pUapsdRspMsg;
    tSirResultCodes  retStatus = eSIR_SME_SUCCESS;

    tANI_U8 PowersavesessionId;
    tpPESession psessionEntry;

    /* we need to process all the deferred messages enqueued since
     * the initiating the SIR_HAL_ENTER_UAPSD_REQ.
     */
    SET_LIM_PROCESS_DEFD_MESGS(pMac, true);

    /* Copy the power save sessionId to the local variable */
    PowersavesessionId = pMac->pmm.sessionId;

    if (NULL == limMsg->bodyptr)
    {
        PELOGE(pmmLog(pMac, LOGE, FL("pmmUapsd: Received SIR_HAL_ENTER_UAPSD_RSP with NULL "));)
        return;
    }

    pUapsdRspMsg = (tpUapsdParams)(limMsg->bodyptr);

    if((psessionEntry = peFindSessionBySessionId(pMac,PowersavesessionId))==NULL)
    {
<<<<<<< HEAD
        pmmLog(pMac, LOGP,FL("Session Does not exist for given sessionID"));
=======
        limLog(pMac, LOGP,FL("Session Does not exist for given sessionID\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        return;
    }

    if(pMac->pmm.gPmmState != ePMM_STATE_UAPSD_WT_SLEEP_RSP)
    {
        PELOGE(pmmLog(pMac, LOGE,
<<<<<<< HEAD
            FL("pmmUapsd: Received SIR_HAL_ENTER_UAPSD_RSP while in incorrect state: %d"),
=======
            FL("pmmUapsd: Received SIR_HAL_ENTER_UAPSD_RSP while in incorrect state: %d\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            pMac->pmm.gPmmState);)
        limSendSmeRsp(pMac, eWNI_PMC_ENTER_UAPSD_RSP, eSIR_SME_INVALID_PMM_STATE, 0, 0);        
        return;
    }

    if(pUapsdRspMsg->status == eHAL_STATUS_SUCCESS)
    {
        PELOGW(pmmLog(pMac, LOGW,
<<<<<<< HEAD
            FL("pmmUapsd: Received successful response from HAL to enter UAPSD mode "));)
=======
            FL("pmmUapsd: Received successful response from HAL to enter UAPSD mode \n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        pMac->pmm.gPmmState = ePMM_STATE_UAPSD_SLEEP;
    }
    else
    {
        PELOGE(pmmLog(pMac, LOGE,
<<<<<<< HEAD
            FL("pmmUapsd: SIR_HAL_ENTER_UAPSD_RSP failed, informing SME"));)
=======
            FL("pmmUapsd: SIR_HAL_ENTER_UAPSD_RSP failed, informing SME\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        pMac->pmm.gPmmState = ePMM_STATE_BMPS_SLEEP;
        retStatus = eSIR_SME_UAPSD_REQ_FAILED;
    }

<<<<<<< HEAD
    if(IS_FEATURE_SUPPORTED_BY_FW(SLM_SESSIONIZATION))
=======
    if(IS_SLM_SESSIONIZATION_SUPPORTED_BY_FW)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    {
        limSendSmeRsp(pMac, eWNI_PMC_ENTER_UAPSD_RSP, retStatus, 
                        psessionEntry->smeSessionId, psessionEntry->transactionId);
    }
    else
    {
        limSendSmeRsp(pMac, eWNI_PMC_ENTER_UAPSD_RSP, retStatus, 0, 0);
    }

    return;
}


// --------------------------------------------------------------------
/**
 * pmmExitUapsdRequestHandler
 *
 * FUNCTION:
 * This function process the eWNI_PMC_EXIT_UAPSD_REQ from PMC,
 * checks the correctness of the system state before configuring
 * PMM to the new ePMM_STATE_UAPSD_WT_WAKEUP_RSP state, and
 * invokes pmmUapsdSendChangePwrSaveMsg() to send
 * SIR_HAL_EXIT_UAPSD_REQ to HAL.
 *
 * NOTE:
 *
 * @param       Global handle to MAC
 * @return      None
 */
void pmmExitUapsdRequestHandler(tpAniSirGlobal pMac)
{
    tSirRetStatus retStatus = eSIR_SUCCESS;
    tSirResultCodes resultCode = eSIR_SME_SUCCESS;

    tPmmState origState = pMac->pmm.gPmmState;

#ifdef FEATURE_WLAN_DIAG_SUPPORT 
    limDiagEventReport(pMac, WLAN_PE_DIAG_EXIT_UAPSD_REQ_EVENT, peGetValidPowerSaveSession(pMac), 0, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT

    if (ePMM_STATE_UAPSD_SLEEP == pMac->pmm.gPmmState)
    {
        pMac->pmm.gPmmState = ePMM_STATE_UAPSD_WT_WAKEUP_RSP;
        if( (retStatus = pmmUapsdSendChangePwrSaveMsg(pMac, SIR_PM_ACTIVE_MODE)) !=
                                                eSIR_SUCCESS)
        {
            PELOGE(pmmLog(pMac, LOGE,
<<<<<<< HEAD
                FL("pmmUapsd: sending EXIT_UAPSD to HAL failed "));)
=======
                FL("pmmUapsd: sending EXIT_UAPSD to HAL failed \n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            resultCode = eSIR_SME_UAPSD_REQ_FAILED;
            goto failure;
        }
    }
    else
    {
        PELOGE(pmmLog(pMac, LOGE,
<<<<<<< HEAD
            FL("pmmUapsd: Rcv EXIT_UAPSD from PMC in invalid state: %x"),
=======
            FL("pmmUapsd: Rcv EXIT_UAPSD from PMC in invalid state: %x\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            pMac->pmm.gPmmState);)

        resultCode = eSIR_SME_INVALID_PMM_STATE;
        goto failure;
    }
    return;

failure:
    pMac->pmm.gPmmState = origState;
    PELOGE(pmmLog(pMac, LOGE,
<<<<<<< HEAD
        FL("pmmUapsd: Waking up from UAPSD mode failed, Ret Code: %d, Next State: %d"),
=======
        FL("pmmUapsd: Waking up from UAPSD mode failed, Ret Code: %d, Next State: %d\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        retStatus, pMac->pmm.gPmmState);)
    limSendSmeRsp(pMac, eWNI_PMC_EXIT_UAPSD_RSP, resultCode, 0, 0);
}


// --------------------------------------------------------------------
/**
 * pmmExitUapsdResponseHandler
 *
 * FUNCTION:
 * This function receives the SIR_HAL_EXIT_UAPSD_RSP from HAL and is
 * responsible for checking the correctness of the system state
 * before configuring PMM to the new ePMM_STATE_BMPS_SLEEP state
 * and send eWNI_PMC_EXIT_UAPSD_RSP to PMC.
 *
 * NOTE:
 *
 * @param       Global handle to MAC
 * @return      None
 */
<<<<<<< HEAD
void pmmExitUapsdResponseHandler(tpAniSirGlobal pMac,  tpSirMsgQ limMsg)
=======
void pmmExitUapsdResponseHandler(tpAniSirGlobal pMac, eHalStatus rspStatus)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
{
    tSirResultCodes resultCode = eSIR_SME_SUCCESS;
    tANI_U8 PowersavesessionId;
    tpPESession psessionEntry;
<<<<<<< HEAD
    tUapsdParams  *pUapsdExitRspParams;
=======
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

    /* we need to process all the deferred messages enqueued since
     * the initiating the SIR_HAL_EXIT_UAPSD_REQ.
     */
    SET_LIM_PROCESS_DEFD_MESGS(pMac, true);

    if (pMac->pmm.gPmmState != ePMM_STATE_UAPSD_WT_WAKEUP_RSP)
    {
        PELOGE(pmmLog(pMac, LOGE,
<<<<<<< HEAD
            FL("Received HAL_EXIT_UAPSD_RSP in invalid state: %d"),
=======
            FL("Received HAL_EXIT_UAPSD_RSP in invalid state: %d\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            pMac->pmm.gPmmState);)
        limSendSmeRsp(pMac, eWNI_PMC_EXIT_UAPSD_RSP, eSIR_SME_INVALID_PMM_STATE, 0, 0);
        return;
    }
<<<<<<< HEAD
    pUapsdExitRspParams = (tUapsdParams *)(limMsg->bodyptr);
=======
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

    PowersavesessionId = pMac->pmm.sessionId;
    if((psessionEntry = peFindSessionBySessionId(pMac,PowersavesessionId))==NULL)
    {
<<<<<<< HEAD
        pmmLog(pMac, LOGP,FL("Session Does not exist for given sessionID"));
        return;
    }

    if(NULL == pUapsdExitRspParams )
    {
        PELOGE(pmmLog(pMac, LOGE,
            FL("Received HAL_EXIT_UAPSD_RSP message with zero parameters:"));)
            limSendSmeRsp(pMac, eWNI_PMC_EXIT_UAPSD_RSP, eSIR_SME_UAPSD_REQ_FAILED, 0, 0);
        return;
    }
    switch(pUapsdExitRspParams->status)
=======
        limLog(pMac, LOGP,FL("Session Does not exist for given sessionID\n"));
        return;
    }

    switch(rspStatus)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    {
        case eHAL_STATUS_SUCCESS:
            resultCode = eSIR_SME_SUCCESS;
            PELOGW(pmmLog(pMac, LOGW,
<<<<<<< HEAD
                FL("Received SIR_HAL_EXIT_UAPSD_RSP with Successful response "));)
=======
                FL("Received SIR_HAL_EXIT_UAPSD_RSP with Successful response \n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            break;
        default:
            resultCode = eSIR_SME_UAPSD_REQ_FAILED;
            PELOGE(pmmLog(pMac, LOGW,
<<<<<<< HEAD
                FL("Received SIR_HAL_EXIT_UAPSD_RSP with Failure Status"));)
=======
                FL("Received SIR_HAL_EXIT_UAPSD_RSP with Failure Status\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            break;
    }

    pMac->pmm.gPmmState = ePMM_STATE_BMPS_SLEEP;

<<<<<<< HEAD
    if(IS_FEATURE_SUPPORTED_BY_FW(SLM_SESSIONIZATION))
=======
    if(IS_SLM_SESSIONIZATION_SUPPORTED_BY_FW)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    {
        limSendSmeRsp(pMac, eWNI_PMC_EXIT_UAPSD_RSP, resultCode, psessionEntry->smeSessionId,
                      psessionEntry->transactionId);
    }
    else
    {
        limSendSmeRsp(pMac, eWNI_PMC_EXIT_UAPSD_RSP, resultCode, 0, 0);
    }
    return;
}

/** ------------------------------------------------------------
\fn      pmmSendWowlAddBcastPtrn
\brief   This function sends a SIR_HAL_WOWL_ADD_BCAST_PTRN
\        message to HAL.
\param   tpAniSirGlobal  pMac
\param   tpSirMsgQ       pMsg
\return  None
  --------------------------------------------------------------*/
void pmmSendWowlAddBcastPtrn(tpAniSirGlobal pMac,  tpSirMsgQ pMsg)
{
    tpSirWowlAddBcastPtrn  pBcastPtrn;
    tSirMbMsg              *pMbMsg = (tSirMbMsg *)pMsg->bodyptr;
    tSirRetStatus          retCode = eSIR_SUCCESS;
    tSirMsgQ               msgQ;

    if (palAllocateMemory(pMac->hHdd, (void **)&pBcastPtrn, sizeof(*pBcastPtrn)) != eHAL_STATUS_SUCCESS)
    {
<<<<<<< HEAD
        pmmLog(pMac, LOGP, FL("Fail to allocate memory for WoWLAN Add Bcast Pattern "));
=======
        pmmLog(pMac, LOGP, FL("Fail to allocate memory for WoWLAN Add Bcast Pattern \n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        return;
    }
    (void) palCopyMemory(pMac->hHdd, pBcastPtrn, pMbMsg->data, sizeof(*pBcastPtrn));

    if (NULL == pBcastPtrn)
    {
<<<<<<< HEAD
        pmmLog(pMac, LOGE, FL("Add broadcast pattern message is NULL "));
=======
        pmmLog(pMac, LOGE, FL("Add broadcast pattern message is NULL \n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        return;
    }

    msgQ.type = WDA_WOWL_ADD_BCAST_PTRN;
    msgQ.reserved = 0;
    msgQ.bodyptr = pBcastPtrn;
    msgQ.bodyval = 0;

    pmmLog(pMac, LOG1, FL( "Sending WDA_WOWL_ADD_BCAST_PTRN to HAL"));
#ifdef FEATURE_WLAN_DIAG_SUPPORT 
    limDiagEventReport(pMac, WLAN_PE_DIAG_WOWL_ADD_BCAST_PTRN_EVENT, NULL, 0, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT

    if( eSIR_SUCCESS != (retCode = wdaPostCtrlMsg( pMac, &msgQ )))
    {
        if (pBcastPtrn != NULL)
            palFreeMemory( pMac->hHdd, (tANI_U8 *) pBcastPtrn);
        pmmLog( pMac, LOGP, FL("Posting WDA_WOWL_ADD_BCAST_PTRN failed, reason=%X"), retCode );
    }
    return;
}

/** ------------------------------------------------------------
\fn      pmmSendWowlDelBcastPtrn
\brief   This function sends a SIR_HAL_WOWL_DEL_BCAST_PTRN
\        message to HAL.
\param   tpAniSirGlobal  pMac
\param   tpSirMsgQ       pMsg
\return  None
  --------------------------------------------------------------*/
void pmmSendWowlDelBcastPtrn(tpAniSirGlobal pMac, tpSirMsgQ pMsg)
{
    tpSirWowlDelBcastPtrn   pDeletePtrn;
    tSirMbMsg               *pMbMsg = (tSirMbMsg *)pMsg->bodyptr;
    tSirRetStatus           retCode = eSIR_SUCCESS;
    tSirMsgQ                msgQ;

    if (palAllocateMemory(pMac->hHdd, (void **)&pDeletePtrn, sizeof(*pDeletePtrn)) != eHAL_STATUS_SUCCESS)
    {
<<<<<<< HEAD
        pmmLog(pMac, LOGP, FL("Fail to allocate memory for WoWLAN Delete Bcast Pattern "));
=======
        pmmLog(pMac, LOGP, FL("Fail to allocate memory for WoWLAN Delete Bcast Pattern \n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        return;
    }
    (void) palCopyMemory(pMac->hHdd, pDeletePtrn, pMbMsg->data, sizeof(*pDeletePtrn));

    if (NULL == pDeletePtrn)
    {
<<<<<<< HEAD
        pmmLog(pMac, LOGE, FL("Delete broadcast pattern message is NULL "));
=======
        pmmLog(pMac, LOGE, FL("Delete broadcast pattern message is NULL \n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        return;
    }

    msgQ.type = WDA_WOWL_DEL_BCAST_PTRN;
    msgQ.reserved = 0;
    msgQ.bodyptr = pDeletePtrn;
    msgQ.bodyval = 0;

    pmmLog(pMac, LOG1, FL( "Sending WDA_WOWL_DEL_BCAST_PTRN"));
#ifdef FEATURE_WLAN_DIAG_SUPPORT 
    limDiagEventReport(pMac, WLAN_PE_DIAG_WOWL_DEL_BCAST_PTRN_EVENT, NULL, 0, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT

    if( eSIR_SUCCESS != (retCode = wdaPostCtrlMsg( pMac, &msgQ )))
    {
        if (NULL != pDeletePtrn)
            palFreeMemory( pMac->hHdd, (tANI_U8 *) pDeletePtrn);
        pmmLog( pMac, LOGP, FL("Posting WDA_WOWL_DEL_BCAST_PTRN failed, reason=%X"), retCode );
    }
    return;
}

/** ---------------------------------------------------------
\fn      pmmEnterWowlRequestHandler
\brief   LIM process the eWNI_PMC_ENTER_WOWL_REQ message, and
\        invokes pmmSendWowlEnterRequest() to send
\        WDA_WOWL_ENTER_REQ message to HAL.
\param   tpAniSirGlobal  pMac
\param   tpSirMsgQ       pMsg
\return  None
 ------------------------------------------------------------*/
void pmmEnterWowlRequestHandler(tpAniSirGlobal pMac, tpSirMsgQ pMsg)
{
    tpSirSmeWowlEnterParams  pSmeWowlParams = NULL;
    tpSirHalWowlEnterParams  pHalWowlParams = NULL;
    tSirRetStatus  retCode = eSIR_SUCCESS;
    tANI_U32  cfgValue = 0;
    tSirMbMsg *pMbMsg = (tSirMbMsg *)pMsg->bodyptr;
<<<<<<< HEAD
    tpPESession pSessionEntry = NULL;
    tANI_U8  peSessionId = 0;
=======
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

#ifdef FEATURE_WLAN_DIAG_SUPPORT 
    limDiagEventReport(pMac, WLAN_PE_DIAG_ENTER_WOWL_REQ_EVENT, NULL, 0, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT

    pSmeWowlParams = (tpSirSmeWowlEnterParams)(pMbMsg->data);
<<<<<<< HEAD
    if (NULL == pSmeWowlParams)
    {
        pmmLog(pMac, LOGE,
               FL("NULL message received"));
        return;
    }

    pSessionEntry = peFindSessionByBssid(pMac, pSmeWowlParams->bssId,
                                         &peSessionId);
    if (NULL == pSessionEntry)
    {
        pmmLog(pMac, LOGE,
               FL("session does not exist for given BSSId"));
        goto end;
    }
    pMac->pmm.sessionId = peSessionId;

=======

    if (NULL == pSmeWowlParams)
        return;
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
// Need to fix it ASAP - TBH
#if 0
    if (pMac->lim.gLimSmeState != eLIM_SME_LINK_EST_STATE)
    {
<<<<<<< HEAD
        pmmLog(pMac, LOGE, FL("Rcvd PMC_ENTER_WOWL_REQ when station is not associated "));
=======
        pmmLog(pMac, LOGE, FL("Rcvd PMC_ENTER_WOWL_REQ when station is not associated \n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        limSendSmeRsp(pMac, eWNI_PMC_ENTER_WOWL_RSP, eSIR_SME_STA_NOT_ASSOCIATED, 0, 0);
        goto end;
    }
#endif


    if ((pMac->pmm.gPmmState != ePMM_STATE_BMPS_SLEEP) && (pMac->pmm.gPmmState != ePMM_STATE_WOWLAN))
    {
<<<<<<< HEAD
        pmmLog(pMac, LOGE, FL("Rcvd PMC_ENTER_WOWL_REQ in invalid Power Save state "));
=======
        pmmLog(pMac, LOGE, FL("Rcvd PMC_ENTER_WOWL_REQ in invalid Power Save state \n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        limSendSmeRsp(pMac, eWNI_PMC_ENTER_WOWL_RSP, eSIR_SME_INVALID_PMM_STATE, 0, 0);
        goto end;
    }

    if (palAllocateMemory(pMac->hHdd, (void **)&pHalWowlParams, sizeof(*pHalWowlParams)) != eHAL_STATUS_SUCCESS)
    {
<<<<<<< HEAD
        pmmLog(pMac, LOGP, FL("Fail to allocate memory for Enter Wowl Request "));
=======
        pmmLog(pMac, LOGP, FL("Fail to allocate memory for Enter Wowl Request \n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        goto end;
    }
    (void) palZeroMemory(pMac->hHdd, (tANI_U8 *)pHalWowlParams, sizeof(*pHalWowlParams) );

    // fill in the message field
    pHalWowlParams->ucMagicPktEnable = pSmeWowlParams->ucMagicPktEnable;
    pHalWowlParams->ucPatternFilteringEnable = pSmeWowlParams->ucPatternFilteringEnable;
    (void)palCopyMemory( pMac->hHdd, (tANI_U8 *)pHalWowlParams->magicPtrn, (tANI_U8 *)pSmeWowlParams->magicPtrn, sizeof(tSirMacAddr) );

#ifdef WLAN_WAKEUP_EVENTS
    pHalWowlParams->ucWoWEAPIDRequestEnable = pSmeWowlParams->ucWoWEAPIDRequestEnable;
    pHalWowlParams->ucWoWEAPOL4WayEnable = pSmeWowlParams->ucWoWEAPOL4WayEnable;
    pHalWowlParams->ucWowNetScanOffloadMatch = pSmeWowlParams->ucWowNetScanOffloadMatch;
    pHalWowlParams->ucWowGTKRekeyError = pSmeWowlParams->ucWowGTKRekeyError;
    pHalWowlParams->ucWoWBSSConnLoss = pSmeWowlParams->ucWoWBSSConnLoss;
#endif // WLAN_WAKEUP_EVENTS

<<<<<<< HEAD
    pHalWowlParams->bssIdx = pSessionEntry->bssIdx;

    if(wlan_cfgGetInt(pMac, WNI_CFG_WOWLAN_UCAST_PATTERN_FILTER_ENABLE, &cfgValue) != eSIR_SUCCESS)
    {
        pmmLog(pMac, LOGP, FL("cfgGet failed for WNI_CFG_WOWLAN_UCAST_PATTERN_FILTER_ENABLE"));
=======
    if(wlan_cfgGetInt(pMac, WNI_CFG_WOWLAN_UCAST_PATTERN_FILTER_ENABLE, &cfgValue) != eSIR_SUCCESS)
    {
        limLog(pMac, LOGP, FL("cfgGet failed for WNI_CFG_WOWLAN_UCAST_PATTERN_FILTER_ENABLE"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        goto end;
    }
    pHalWowlParams->ucUcastPatternFilteringEnable = (tANI_U8)cfgValue;

    if(wlan_cfgGetInt(pMac, WNI_CFG_WOWLAN_CHANNEL_SWITCH_ENABLE, &cfgValue) != eSIR_SUCCESS)
    {
<<<<<<< HEAD
        pmmLog(pMac, LOGP, FL("cfgGet failed for WNI_CFG_WOWLAN_CHANNEL_SWITCH_ENABLE"));
=======
        limLog(pMac, LOGP, FL("cfgGet failed for WNI_CFG_WOWLAN_CHANNEL_SWITCH_ENABLE"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        goto end;
    }
    pHalWowlParams->ucWowChnlSwitchRcv = (tANI_U8)cfgValue;

    if(wlan_cfgGetInt(pMac, WNI_CFG_WOWLAN_DEAUTH_ENABLE, &cfgValue) != eSIR_SUCCESS)
    {
<<<<<<< HEAD
       pmmLog(pMac, LOGP, FL("cfgGet failed for WNI_CFG_WOWLAN_DEAUTH_ENABLE "));
=======
       limLog(pMac, LOGP, FL("cfgGet failed for WNI_CFG_WOWLAN_DEAUTH_ENABLE \n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
       goto end;
    }
    pHalWowlParams->ucWowDeauthRcv = (tANI_U8)cfgValue;

    if(wlan_cfgGetInt(pMac, WNI_CFG_WOWLAN_DISASSOC_ENABLE, &cfgValue) != eSIR_SUCCESS)
    {
<<<<<<< HEAD
        pmmLog(pMac, LOGP, FL("cfgGet failed for WNI_CFG_WOWLAN_DEAUTH_ENABLE "));
=======
        limLog(pMac, LOGP, FL("cfgGet failed for WNI_CFG_WOWLAN_DEAUTH_ENABLE \n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        goto end;
    }
    pHalWowlParams->ucWowDisassocRcv = (tANI_U8)cfgValue;

    if(wlan_cfgGetInt(pMac, WNI_CFG_WOWLAN_MAX_MISSED_BEACON, &cfgValue) != eSIR_SUCCESS)
    {
<<<<<<< HEAD
        pmmLog(pMac, LOGP, FL("cfgGet failed for WNI_CFG_WOWLAN_MAX_MISSED_BEACON "));
=======
        limLog(pMac, LOGP, FL("cfgGet failed for WNI_CFG_WOWLAN_MAX_MISSED_BEACON \n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        goto end;
    }
    pHalWowlParams->ucWowMaxMissedBeacons = (tANI_U8)cfgValue;

    if(wlan_cfgGetInt(pMac, WNI_CFG_WOWLAN_MAX_SLEEP_PERIOD, &cfgValue) != eSIR_SUCCESS)
    {
<<<<<<< HEAD
        pmmLog(pMac, LOGP, FL("cfgGet failed for WNI_CFG_WOWLAN_MAX_SLEEP_PERIOD "));
=======
        limLog(pMac, LOGP, FL("cfgGet failed for WNI_CFG_WOWLAN_MAX_SLEEP_PERIOD \n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        goto end;
    }
    pHalWowlParams->ucWowMaxSleepUsec = (tANI_U8)cfgValue;

    //Send message to HAL
    if( eSIR_SUCCESS != (retCode = pmmSendWowlEnterRequest( pMac, pHalWowlParams)))
    {
<<<<<<< HEAD
        pmmLog(pMac, LOGE, FL("Send ENTER_WOWL_REQ to HAL failed, reasonCode %d "), retCode);
=======
        pmmLog(pMac, LOGE, FL("Send ENTER_WOWL_REQ to HAL failed, reasonCode %d \n"), retCode);
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        limSendSmeRsp(pMac, eWNI_PMC_ENTER_WOWL_RSP, eSIR_SME_WOWL_ENTER_REQ_FAILED, 0, 0);
        goto end;
    }
    return;

end:
    if (pHalWowlParams != NULL)
        palFreeMemory( pMac->hHdd, (tANI_U8 *) pHalWowlParams);
    return;
}


/** ------------------------------------------------------------
\fn      pmmSendWowlEnterRequest
\brief   LIM sends a WDA_WOWL_ENTER_REQ message to HAL with
\        the message structure pHalWowlParams.  HAL shall later
\        send a WDA_WOWL_ENTER_RSP with the same pointer
\        to the message structure back to PMM.
\param   tpAniSirGlobal           pMac
\param   tpSirHalWowlEnterParams  pHalWowlParams
\return  tSirRetStatus
  --------------------------------------------------------------*/
tSirRetStatus pmmSendWowlEnterRequest(tpAniSirGlobal pMac, tpSirHalWowlEnterParams pHalWowlParams)
{
    tSirRetStatus             retCode = eSIR_SUCCESS;
    tSirMsgQ                  msgQ;

    if (NULL == pHalWowlParams)
        return eSIR_FAILURE;

    msgQ.type = WDA_WOWL_ENTER_REQ;
    msgQ.reserved = 0;
    msgQ.bodyptr = pHalWowlParams;
    msgQ.bodyval = 0;

    /* Defer any incoming message until we get
     * a WDA_WOWL_ENTER_RSP from HAL
     */
    SET_LIM_PROCESS_DEFD_MESGS(pMac, false);

    retCode = wdaPostCtrlMsg(pMac, &msgQ);
    if( eSIR_SUCCESS != retCode )
    {
        pmmLog( pMac, LOGE, FL("Posting WDA_WOWL_ENTER_REQ failed, reason=%X"), retCode );
        return retCode;
    }
    return retCode;
}

/** ---------------------------------------------------------
\fn      pmmEnterWowlanResponseHandler
\brief   LIM process the WDA_WOWL_ENTER_RSP message.
\        and sends eWNI_PMC_ENTER_WOWL_RSP to SME.
\param   tpAniSirGlobal  pMac
\param   tpSirMsgQ       limMsg
\return  None
 ------------------------------------------------------------*/
void pmmEnterWowlanResponseHandler(tpAniSirGlobal pMac, tpSirMsgQ limMsg)
{
<<<<<<< HEAD
    tpSirHalWowlEnterParams  pWowlEnterParams;
    eHalStatus               rspStatus;
=======
    tpSirHalWowlEnterParams  pHalWowlMsg;
    eHalStatus            rspStatus;
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    tSirResultCodes          smeRspCode = eSIR_SME_SUCCESS;

    /* we need to process all the deferred messages enqueued
     * since the initiating the WDA_WOWL_ENTER_REQ.
     */
    SET_LIM_PROCESS_DEFD_MESGS(pMac, true);

<<<<<<< HEAD
    pWowlEnterParams = (tpSirHalWowlEnterParams)(limMsg->bodyptr);
    if (NULL == pWowlEnterParams)
=======
    pHalWowlMsg = (tpSirHalWowlEnterParams)(limMsg->bodyptr);
    if (NULL == pHalWowlMsg)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    {
        pmmLog(pMac, LOGE, FL("Recvd WDA_WOWL_ENTER_RSP with NULL msg "));
        smeRspCode = eSIR_SME_WOWL_ENTER_REQ_FAILED;
    }
    else
    {
<<<<<<< HEAD
        rspStatus = pWowlEnterParams->status;

        if(rspStatus == eHAL_STATUS_SUCCESS)
        {
            pmmLog(pMac, LOGW, FL("Rcv successful response from HAL to enter WOWLAN "));
=======
        rspStatus = pHalWowlMsg->status;
        if(rspStatus == eHAL_STATUS_SUCCESS)
        {
            pmmLog(pMac, LOGW, FL("Rcv successful response from HAL to enter WOWLAN \n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            pMac->pmm.gPmmState = ePMM_STATE_WOWLAN;
        }
        else
        {
<<<<<<< HEAD
            pmmLog(pMac, LOGE, FL("HAL enter WOWLAN failed, informing SME"));
=======
            pmmLog(pMac, LOGE, FL("HAL enter WOWLAN failed, informing SME\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            smeRspCode = eSIR_SME_WOWL_ENTER_REQ_FAILED;
        }
    }

    limSendSmeRsp(pMac, eWNI_PMC_ENTER_WOWL_RSP, smeRspCode, 0, 0);
    return;
}

/** ---------------------------------------------------------
\fn      pmmExitWowlanRequestHandler
\brief   PE process the eWNI_PMC_EXIT_WOWL_REQ message.
\        and sends WDA_WOWL_EXIT_REQ to HAL.
\param   tpAniSirGlobal  pMac
\return  None
 ------------------------------------------------------------*/
void pmmExitWowlanRequestHandler(tpAniSirGlobal pMac)
{
    tSirRetStatus retStatus = eSIR_SUCCESS;
    tSirResultCodes smeRspCode = eSIR_SME_SUCCESS;
<<<<<<< HEAD
    tpPESession pSessionEntry;
    tpSirHalWowlExitParams  pHalWowlMsg = NULL;
    tANI_U8            PowersavesessionId = 0;

    PowersavesessionId = pMac->pmm.sessionId;

    if((pSessionEntry = peFindSessionBySessionId(pMac,PowersavesessionId)) == NULL )
    {
        PELOGW(pmmLog(pMac, LOGE, FL("pmmWowl :palAllocateMemory() failed"));)
        smeRspCode = eSIR_SME_WOWL_EXIT_REQ_FAILED;
        goto failure;
    }

    if (palAllocateMemory(pMac->hHdd, (void **)&pHalWowlMsg, sizeof(*pHalWowlMsg)) != eHAL_STATUS_SUCCESS)
    {
        pmmLog(pMac, LOGP, FL("Fail to allocate memory for WoWLAN Add Bcast Pattern "));
        smeRspCode = eSIR_SME_WOWL_EXIT_REQ_FAILED;
        goto failure;
    }
=======
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

#ifdef FEATURE_WLAN_DIAG_SUPPORT 
    limDiagEventReport(pMac, WLAN_PE_DIAG_EXIT_WOWL_REQ_EVENT, NULL, 0, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT

    if ( pMac->pmm.gPmmState != ePMM_STATE_WOWLAN )
    {
        pmmLog(pMac, LOGE,
<<<<<<< HEAD
            FL("Exit WOWLAN Request received in invalid state PMM=%d "),
=======
            FL("Exit WOWLAN Request received in invalid state PMM=%d \n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            pMac->pmm.gPmmState);
        smeRspCode = eSIR_SME_INVALID_PMM_STATE;
        goto failure;
    }

<<<<<<< HEAD
    (void) palZeroMemory(pMac->hHdd, (tANI_U8 *)pHalWowlMsg, sizeof(*pHalWowlMsg) );
    pHalWowlMsg->bssIdx = pSessionEntry->bssIdx;

    if((retStatus = pmmSendExitWowlReq(pMac, pHalWowlMsg)) != eSIR_SUCCESS)
    {
        pmmLog(pMac, LOGE,
            FL("Fail to send WDA_WOWL_EXIT_REQ, reason code %d"),
=======
    if((retStatus = pmmSendExitWowlReq(pMac)) != eSIR_SUCCESS)
    {
        pmmLog(pMac, LOGE,
            FL("Fail to send WDA_WOWL_EXIT_REQ, reason code %d\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            retStatus);
        smeRspCode = eSIR_SME_WOWL_EXIT_REQ_FAILED;
        goto failure;
    }
    return;

failure:
<<<<<<< HEAD
    if (pHalWowlMsg != NULL)
        palFreeMemory( pMac->hHdd, (tANI_U8 *) pHalWowlMsg);
=======
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    limSendSmeRsp(pMac, eWNI_PMC_EXIT_WOWL_RSP, smeRspCode, 0, 0);
    return;
}

/** ---------------------------------------------------------
\fn      pmmSendExitWowlReq
\brief   This function sends the WDA_WOWL_EXIT_REQ
\        message to HAL.
\param   tpAniSirGlobal  pMac
\return  None
 ------------------------------------------------------------*/
<<<<<<< HEAD
tSirRetStatus  pmmSendExitWowlReq(tpAniSirGlobal pMac, tpSirHalWowlExitParams pHalWowlParams)
=======
tSirRetStatus  pmmSendExitWowlReq(tpAniSirGlobal pMac)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
{
    tSirRetStatus  retCode = eSIR_SUCCESS;
    tSirMsgQ       msgQ;

<<<<<<< HEAD
    if (NULL == pHalWowlParams)
        return eSIR_FAILURE;

    msgQ.type = WDA_WOWL_EXIT_REQ;
    msgQ.reserved = 0;
    msgQ.bodyptr = pHalWowlParams;
=======
    msgQ.type = WDA_WOWL_EXIT_REQ;
    msgQ.reserved = 0;
    msgQ.bodyptr = 0;
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    msgQ.bodyval = 0;

    pmmLog(pMac, LOGW, FL("Sending WDA_WOWL_EXIT_REQ"));

    /* we need to defer any incoming messages until
     * we get a WDA_WOWL_EXIT_RSP from HAL.
     */
    SET_LIM_PROCESS_DEFD_MESGS(pMac, false);

    if( eSIR_SUCCESS != (retCode = wdaPostCtrlMsg( pMac, &msgQ )))
        pmmLog( pMac, LOGE,
<<<<<<< HEAD
            FL("Posting WDA_WOWL_EXIT_REQ failed, reason=%X"),
=======
            FL("Posting WDA_WOWL_EXIT_REQ failed, reason=%X\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            retCode );

    return retCode;
}

/** ---------------------------------------------------------
\fn      pmmExitWowlanResponseHandler
\brief   This function process the WDA_WOWL_EXIT_RSP message.
\        and sends back eWNI_PMC_EXIT_WOWL_RSP to SME.
\param   tpAniSirGlobal  pMac
\return  None
 ------------------------------------------------------------*/
<<<<<<< HEAD
void pmmExitWowlanResponseHandler(tpAniSirGlobal pMac, tpSirMsgQ limMsg)
{

    tpSirHalWowlExitParams  pHalWowlRspMsg;
    eHalStatus   rspStatus = eHAL_STATUS_FAILURE;

=======
void pmmExitWowlanResponseHandler(tpAniSirGlobal pMac, eHalStatus rspStatus)
{
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    /* we need to process all the deferred messages enqueued
     * since the initiating the WDA_WOWL_EXIT_REQ.
     */
    SET_LIM_PROCESS_DEFD_MESGS(pMac, true);

<<<<<<< HEAD
    pHalWowlRspMsg = (tpSirHalWowlExitParams)(limMsg->bodyptr);
    if (NULL == pHalWowlRspMsg)
    {
        pmmLog(pMac, LOGE, FL("Recvd WDA_WOWL_ENTER_RSP with NULL msg "));
    }
    else
    {
        // restore PMM state to BMPS mode
        pMac->pmm.gPmmState = ePMM_STATE_BMPS_SLEEP;
        rspStatus = pHalWowlRspMsg->status;
    }

    if( rspStatus == eHAL_STATUS_SUCCESS)
    {
        pmmLog(pMac, LOGW, FL("Rcvd successful rsp from HAL to exit WOWLAN "));
=======
    // restore PMM state to BMPS mode
    pMac->pmm.gPmmState = ePMM_STATE_BMPS_SLEEP;

    if(rspStatus == eHAL_STATUS_SUCCESS)
    {
        pmmLog(pMac, LOGW, FL("Rcvd successful rsp from HAL to exit WOWLAN \n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        limSendSmeRsp(pMac, eWNI_PMC_EXIT_WOWL_RSP, eSIR_SME_SUCCESS, 0, 0);
    }
    else
    {
<<<<<<< HEAD
        pmmLog(pMac, LOGE, FL("Rcvd failure rsp from HAL to exit WOWLAN "));
=======
        pmmLog(pMac, LOGE, FL("Rcvd failure rsp from HAL to exit WOWLAN \n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        limSendSmeRsp(pMac, eWNI_PMC_EXIT_WOWL_RSP, eSIR_SME_WOWL_EXIT_REQ_FAILED, 0, 0);
    }
    return;
}


// --------------------------------------------------------------------
/**
 * pmmImpsSendChangePwrSaveMsg
 *
 * FUNCTION:
 * This function is called to toggle the Idle mode power save mode
 *
 * LOGIC:
 *
 * ASSUMPTIONS:
 * None
 *
 * NOTE:
 *
 * @param   Global handle to MAC
 * @param   mode to be configured
 * @return  None
 */

tSirRetStatus pmmImpsSendChangePwrSaveMsg(tpAniSirGlobal pMac, tANI_U8 mode)
{
    tSirRetStatus retStatus = eSIR_SUCCESS;
    tSirMsgQ msgQ;

    if (SIR_PM_SLEEP_MODE == mode)
    {
        msgQ.type = WDA_ENTER_IMPS_REQ;
<<<<<<< HEAD
        PELOG2(pmmLog (pMac, LOG2, FL("Sending WDA_ENTER_IMPS_REQ to HAL"));)
=======
        PELOG2(pmmLog (pMac, LOG2, FL("Sending WDA_ENTER_IMPS_REQ to HAL\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    }
    else
    {
        msgQ.type = WDA_EXIT_IMPS_REQ;
<<<<<<< HEAD
        PELOG2(pmmLog (pMac, LOG2, FL("Sending WDA_EXIT_IMPS_REQ to HAL"));)
=======
        PELOG2(pmmLog (pMac, LOG2, FL("Sending WDA_EXIT_IMPS_REQ to HAL\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    }

    msgQ.reserved = 0;
    msgQ.bodyptr = NULL;
    msgQ.bodyval = 0;

    /* we need to defer any incoming messages until we get a
     * WDA_ENTER_IMPS_REQ or WDA_EXIT_IMPS_RSP from HAL.
     */
    SET_LIM_PROCESS_DEFD_MESGS(pMac, false);
    MTRACE(macTraceMsgTx(pMac, NO_SESSION, msgQ.type));
    retStatus = wdaPostCtrlMsg(pMac, &msgQ);
    if ( eSIR_SUCCESS != retStatus )
    {
        PELOGE(pmmLog(pMac, LOGE, 
<<<<<<< HEAD
            FL("WDA_ENTER/EXIT_IMPS_REQ to HAL failed, reason=%X"), retStatus);)
=======
            FL("WDA_ENTER/EXIT_IMPS_REQ to HAL failed, reason=%X\n"), retStatus);)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    }

    return retStatus;
}

// --------------------------------------------------------------------
/**
 * pmmUapsdSendChangePwrSaveMsg
 *
 * FUNCTION:
 * This function is called to send either WDA_ENTER_UAPSD_REQ
 * or WDA_EXIT_UAPSD_REQ to HAL.
 *
 * NOTE:
 *
 * @param   pMac     Global handle to MAC
 * @param   mode     mode to be configured
 * @return  tSirRetStatus
 */
tSirRetStatus pmmUapsdSendChangePwrSaveMsg (tpAniSirGlobal pMac, tANI_U8 mode)
{
    tSirRetStatus retStatus = eSIR_SUCCESS;
    tpUapsdParams pUapsdParams = NULL;
    tANI_U8  uapsdDeliveryMask = 0;
    tANI_U8  uapsdTriggerMask = 0;
    tSirMsgQ msgQ;
    tpPESession pSessionEntry;
<<<<<<< HEAD
    tpExitUapsdParams pExitUapsdParams = NULL;

    if((pSessionEntry = peGetValidPowerSaveSession(pMac)) == NULL )
    {
        PELOGW(pmmLog(pMac, LOGW, FL("pmmUapsd :palAllocateMemory() failed"));)
        retStatus = eSIR_FAILURE;
        return retStatus;
    }
=======
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

    if (SIR_PM_SLEEP_MODE == mode)
    {
        if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pUapsdParams, sizeof(tUapsdParams)) )
        {
<<<<<<< HEAD
            PELOGW(pmmLog(pMac, LOGW, FL("pmmUapsd :palAllocateMemory() failed"));)
=======
            PELOGW(pmmLog(pMac, LOGW, FL("pmmUapsd :palAllocateMemory() failed\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            retStatus = eSIR_MEM_ALLOC_FAILED;
            return retStatus;
        }

<<<<<<< HEAD
=======
        if((pSessionEntry = peGetValidPowerSaveSession(pMac)) == NULL )
        {
            PELOGW(pmmLog(pMac, LOGW, FL("pmmUapsd :palAllocateMemory() failed\n"));)
            retStatus = eSIR_FAILURE;
            return retStatus;
        }
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        palZeroMemory( pMac->hHdd, (tANI_U8 *)pUapsdParams, sizeof(tUapsdParams));
        msgQ.type = WDA_ENTER_UAPSD_REQ;
        msgQ.bodyptr = pUapsdParams;

        uapsdDeliveryMask = (pMac->lim.gUapsdPerAcBitmask | pMac->lim.gUapsdPerAcDeliveryEnableMask);
        uapsdTriggerMask = (pMac->lim.gUapsdPerAcBitmask | pMac->lim.gUapsdPerAcTriggerEnableMask);

        pUapsdParams->bkDeliveryEnabled = LIM_UAPSD_GET(ACBK, uapsdDeliveryMask);
        pUapsdParams->beDeliveryEnabled = LIM_UAPSD_GET(ACBE, uapsdDeliveryMask);
        pUapsdParams->viDeliveryEnabled = LIM_UAPSD_GET(ACVI, uapsdDeliveryMask);
        pUapsdParams->voDeliveryEnabled = LIM_UAPSD_GET(ACVO, uapsdDeliveryMask);
        pUapsdParams->bkTriggerEnabled = LIM_UAPSD_GET(ACBK, uapsdTriggerMask);
        pUapsdParams->beTriggerEnabled = LIM_UAPSD_GET(ACBE, uapsdTriggerMask);
        pUapsdParams->viTriggerEnabled = LIM_UAPSD_GET(ACVI, uapsdTriggerMask);
        pUapsdParams->voTriggerEnabled = LIM_UAPSD_GET(ACVO, uapsdTriggerMask);
        pUapsdParams->bssIdx = pSessionEntry->bssIdx;

        PELOGE(pmmLog(pMac, LOGE, 
<<<<<<< HEAD
                      FL("UAPSD Mask:  static = 0x%x, DeliveryEnabled = 0x%x, TriggerEnabled = 0x%x "),
=======
                      FL("UAPSD Mask:  static = 0x%x, DeliveryEnabled = 0x%x, TriggerEnabled = 0x%x \n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            pMac->lim.gUapsdPerAcBitmask,
            pMac->lim.gUapsdPerAcDeliveryEnableMask,
            pMac->lim.gUapsdPerAcTriggerEnableMask);)

<<<<<<< HEAD
        PELOG1(pmmLog(pMac, LOG1, FL("Delivery Enabled: BK=%d, BE=%d, Vi=%d, Vo=%d "),
=======
        PELOG1(pmmLog(pMac, LOG1, FL("Delivery Enabled: BK=%d, BE=%d, Vi=%d, Vo=%d \n"), 
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            pUapsdParams->bkDeliveryEnabled, 
            pUapsdParams->beDeliveryEnabled, 
            pUapsdParams->viDeliveryEnabled, 
            pUapsdParams->voDeliveryEnabled);)

<<<<<<< HEAD
        PELOG1(pmmLog(pMac, LOG1, FL("Trigger Enabled: BK=%d, BE=%d, Vi=%d, Vo=%d "),
=======
        PELOG1(pmmLog(pMac, LOG1, FL("Trigger Enabled: BK=%d, BE=%d, Vi=%d, Vo=%d \n"), 
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            pUapsdParams->bkTriggerEnabled, 
            pUapsdParams->beTriggerEnabled, 
            pUapsdParams->viTriggerEnabled, 
            pUapsdParams->voTriggerEnabled);)

<<<<<<< HEAD
        PELOGW(pmmLog (pMac, LOGW, FL("pmmUapsd: Sending WDA_ENTER_UAPSD_REQ to HAL"));)
    }
    else
    {
        if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pExitUapsdParams, sizeof(tExitUapsdParams)) )
        {
            PELOGW(pmmLog(pMac, LOGW, FL("pmmUapsd :palAllocateMemory() failed"));)
            retStatus = eSIR_MEM_ALLOC_FAILED;
            return retStatus;
        }

        palZeroMemory( pMac->hHdd, (tANI_U8 *)pExitUapsdParams, sizeof(tExitUapsdParams));
        msgQ.type = WDA_EXIT_UAPSD_REQ;
        msgQ.bodyptr = pExitUapsdParams;
        pExitUapsdParams->bssIdx = pSessionEntry->bssIdx;
        PELOGW(pmmLog (pMac, LOGW, FL("pmmUapsd: Sending WDA_EXIT_UAPSD_REQ to HAL"));)
=======
        PELOGW(pmmLog (pMac, LOGW, FL("pmmUapsd: Sending WDA_ENTER_UAPSD_REQ to HAL\n"));)
    }
    else
    {
        msgQ.type = WDA_EXIT_UAPSD_REQ;
        msgQ.bodyptr = NULL;
        PELOGW(pmmLog (pMac, LOGW, FL("pmmUapsd: Sending WDA_EXIT_UAPSD_REQ to HAL\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    }

    /* we need to defer any incoming messages until we get a
     * WDA_ENTER/EXIT_UAPSD_RSP from HAL.
     */
    SET_LIM_PROCESS_DEFD_MESGS(pMac, false);

    msgQ.reserved = 0;
    msgQ.bodyval = 0;
    MTRACE(macTraceMsgTx(pMac, NO_SESSION, msgQ.type));
    retStatus = wdaPostCtrlMsg(pMac, &msgQ);
    if ( eSIR_SUCCESS != retStatus )
    {
        PELOGE(pmmLog(pMac, LOGE, 
<<<<<<< HEAD
            FL("pmmUapsd: WDA_ENTER/EXIT_UAPSD_REQ to HAL failed, reason=%X"),
            retStatus);)
        if (SIR_PM_SLEEP_MODE == mode)
            palFreeMemory(pMac->hHdd, (tANI_U8*)pUapsdParams);
        else
            palFreeMemory(pMac->hHdd, (tANI_U8*)pExitUapsdParams);
=======
            FL("pmmUapsd: WDA_ENTER/EXIT_UAPSD_REQ to HAL failed, reason=%X\n"),
            retStatus);)
        if (SIR_PM_SLEEP_MODE == mode)
            palFreeMemory(pMac->hHdd, (tANI_U8*)pUapsdParams);
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    }

    return retStatus;
}


// --------------------------------------------------------------------
/**
 * pmmUpdateImpsPwrSaveStats
 *
 * FUNCTION:
 * This function is called to update the power save statistics in MAC
 * for Idle mode power save
 *
 * LOGIC:
 *
 * ASSUMPTIONS:
 * None
 *
 * NOTE:
 *
 * @param   Global handle to MAC
 * @return  None
 */

void pmmImpsUpdatePwrSaveStats(tpAniSirGlobal pMac)
{
/*
    tANI_U64 TimeAwake = 0;

    pMac->pmm.ImpsSleepTimeStamp = vos_timer_get_system_ticks();

    if (pMac->pmm.ImpsWakeupTimeStamp)
    {
        TimeAwake = (pMac->pmm.ImpsSleepTimeStamp - pMac->pmm.ImpsWakeupTimeStamp) / 10 ;
    }
    else
    {
        TimeAwake = 0;
    }

    if (TimeAwake > pMac->pmm.ImpsMaxTimeAwake)
    {
        pMac->pmm.ImpsMaxTimeAwake = TimeAwake;
    }

    if ((!pMac->pmm.ImpsMinTimeAwake) || (TimeAwake < pMac->pmm.ImpsMinTimeAwake))
    {
        pMac->pmm.ImpsMinTimeAwake = TimeAwake;
    }

    pMac->pmm.ImpsAvgTimeAwake = ((pMac->pmm.ImpsAvgTimeAwake * pMac->pmm.ImpsCntSleep) + TimeAwake) / (pMac->pmm.ImpsCntSleep + 1);

    (pMac->pmm.ImpsCntSleep)++;

    return;
*/
}


// --------------------------------------------------------------------
/**
 * pmmImpsUpdateWakeupStats
 *
 * FUNCTION:
 * This function is called to update the Wake up statistics in MAC
 * for Idle mode power save
 *
 * LOGIC:
 *
 * ASSUMPTIONS:
 * None
 *
 * NOTE:
 *
 * @param   Global handle to MAC
 * @return  None
 */

void pmmImpsUpdateWakeupStats (tpAniSirGlobal pMac)
{
/*
    tANI_U64 SleepTime = 0;

    pMac->pmm.ImpsWakeupTimeStamp = vos_timer_get_system_ticks();

    SleepTime = (pMac->pmm.ImpsWakeupTimeStamp - pMac->pmm.ImpsSleepTimeStamp) / 10;

    if (SleepTime > pMac->pmm.ImpsMaxSleepTime)
    {
        pMac->pmm.ImpsMaxSleepTime = SleepTime;
    }

    if ((!pMac->pmm.ImpsMinSleepTime) || (SleepTime < pMac->pmm.ImpsMinSleepTime))
    {
        pMac->pmm.ImpsMinSleepTime = SleepTime;
    }

    pMac->pmm.ImpsAvgSleepTime = ( ( (pMac->pmm.ImpsAvgSleepTime * pMac->pmm.ImpsCntAwake) + SleepTime) / (pMac->pmm.ImpsCntAwake + 1));

    (pMac->pmm.ImpsCntAwake)++;

    return;
*/
}

// Collects number of times error occurred while going to sleep mode
void pmmImpsUpdateSleepErrStats(tpAniSirGlobal pMac,
                                tSirRetStatus retStatus)
{
    pMac->pmm.ImpsSleepErrCnt++;
    pMac->pmm.ImpsLastErr = retStatus;
    return;
}

// Collects number of times error occurred while waking up from sleep mode
void pmmImpsUpdateWakeupErrStats(tpAniSirGlobal pMac,
                                 tSirRetStatus retStatus)
{
    pMac->pmm.ImpsWakeupErrCnt++;
    pMac->pmm.ImpsLastErr = retStatus;
    return;
}


// Collects number of times the system has received request or
// response in an invalid state
void pmmImpsUpdateErrStateStats(tpAniSirGlobal pMac)
{
    pMac->pmm.ImpsInvalidStateCnt++;
    return;
}

// Collects number of packets dropped while in IMPS mode
void pmmImpsUpdatePktDropStats(tpAniSirGlobal pMac)
{

    pMac->pmm.ImpsPktDrpInSleepMode++;
    return;
}

// Collects number of packets dropped while in BMPS mode
void pmmBmpsUpdatePktDropStats(tpAniSirGlobal pMac)
{

    pMac->pmm.BmpsPktDrpInSleepMode++;
    return;
}

// Collects statistics for number of times BMPS init failed
void pmmBmpsUpdateInitFailureCnt(tpAniSirGlobal pMac)
{

    pMac->pmm.BmpsInitFailCnt++;
    return;
}

// Collects statistics for number of times sleep request failed
void pmmBmpsUpdateSleepReqFailureCnt(tpAniSirGlobal pMac)
{

    pMac->pmm.BmpsSleeReqFailCnt++;
    return;
}

// Collects statistics for number of times Wakeup request failed
void pmmBmpsUpdateWakeupReqFailureCnt(tpAniSirGlobal pMac)
{

    pMac->pmm.BmpsWakeupReqFailCnt++;
    return;
}

// Collects statistics for number of times request / response received in invalid state
void pmmBmpsUpdateInvalidStateCnt(tpAniSirGlobal pMac)
{

    pMac->pmm.BmpsInvStateCnt++;
    return;
}

// Collects statistics for number of times wakeup indications received
void pmmBmpsUpdateWakeupIndCnt(tpAniSirGlobal pMac)
{
    pMac->pmm.BmpsWakeupIndCnt++;
    return;
}

// Collects statistics for number of times wakeup indications received
void pmmBmpsUpdateHalReqFailureCnt(tpAniSirGlobal pMac)
{
    pMac->pmm.BmpsHalReqFailCnt++;
    return;
}

// Collects statistics for number of times requests received from HDD in
// invalid device role
void pmmBmpsUpdateReqInInvalidRoleCnt(tpAniSirGlobal pMac)
{
    pMac->pmm.BmpsReqInInvalidRoleCnt++;
    return;
}

#if 0
// Update the sleep statistics
void pmmUpdateDroppedPktStats(tpAniSirGlobal pMac)
{
    switch (pMac->pmm.gPmmState)
    {
    case ePMM_STATE_BMPS_SLEEP:
        pmmBmpsUpdatePktDropStats(pMac);
        break;

    case ePMM_STATE_IMPS_SLEEP:
        pmmImpsUpdatePktDropStats(pMac);
        break;

    default:
        break;
    }
    return;

}
#endif

// Resets PMM state ePMM_STATE_READY
void pmmResetPmmState(tpAniSirGlobal pMac)
{
    pMac->pmm.gPmmState = ePMM_STATE_READY;
    
    pMac->pmm.inMissedBeaconScenario = FALSE;
    return;
}

/* Sends Background scan message back to Lim */
void pmmSendMessageToLim(tpAniSirGlobal pMac,
                         tANI_U32 msgId)
{
    tSirMsgQ limMsg;
    tANI_U32 statusCode;

    limMsg.type = (tANI_U16) msgId;
    limMsg.bodyptr = NULL;
    limMsg.bodyval = 0;

    if ((statusCode = limPostMsgApi(pMac, &limMsg)) != eSIR_SUCCESS)
    {
          PELOGW(pmmLog(pMac, LOGW,
<<<<<<< HEAD
            FL("posting message %X to LIM failed, reason=%d"),
=======
            FL("posting message %X to LIM failed, reason=%d\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            limMsg.type, statusCode);)
    }
}

#ifdef WLAN_FEATURE_PACKET_FILTERING
void pmmFilterMatchCountResponseHandler(tpAniSirGlobal pMac, tpSirMsgQ limMsg)
{
    tpSirRcvFltPktMatchRsp  pRcvFltPktMatchCntRsp;
    eHalStatus              rspStatus;
    tSirResultCodes         smeRspCode = eSIR_SME_SUCCESS;

    /* we need to process all the deferred messages enqueued
     * since the initiating the WDA_PACKET_COALESCING_FILTER_MATCH_COUNT_REQ.
     */
    SET_LIM_PROCESS_DEFD_MESGS(pMac, true);

    pRcvFltPktMatchCntRsp = (tpSirRcvFltPktMatchRsp)(limMsg->bodyptr);
    if (NULL == pRcvFltPktMatchCntRsp)
    {
        pmmLog(pMac, LOGE, FL("Received "
            "WDA_PACKET_COALESCING_FILTER_MATCH_COUNT_RSP with NULL msg "));
        smeRspCode = eSIR_SME_PC_FILTER_MATCH_COUNT_REQ_FAILED;
    }
    else
    {
        rspStatus = pRcvFltPktMatchCntRsp->status;
        if (eHAL_STATUS_SUCCESS == rspStatus)
        {
            pmmLog(pMac, LOGE, FL("Rcv successful response from HAL to get "
<<<<<<< HEAD
                "Packet Coalescing Filter Match Count"));
=======
                "Packet Coalescing Filter Match Count\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        }
        else
        {
            pmmLog(pMac, LOGE, FL("HAL failed to get Packet Coalescing "
<<<<<<< HEAD
                "Filter Match Count, informing SME"));
=======
                "Filter Match Count, informing SME\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            smeRspCode = eSIR_SME_PC_FILTER_MATCH_COUNT_REQ_FAILED;
        }
    }

    limSendSmeRsp(pMac, eWNI_PMC_PACKET_COALESCING_FILTER_MATCH_COUNT_RSP, 
                  smeRspCode, 0, 0);
    return;
}
#endif // WLAN_FEATURE_PACKET_FILTERING

#ifdef WLAN_FEATURE_GTK_OFFLOAD
void pmmGTKOffloadGetInfoResponseHandler(tpAniSirGlobal pMac, tpSirMsgQ limMsg)
{
    tpSirGtkOffloadGetInfoRspParams  pGtkOffloadGetInfoRspParams;
    eHalStatus                       rspStatus;
    tSirResultCodes                  smeRspCode = eSIR_SME_SUCCESS;

    /* we need to process all the deferred messages enqueued
     * since the initiating the WDA_GTK_OFFLOAD_GETINFO_REQ.
     */
    SET_LIM_PROCESS_DEFD_MESGS(pMac, true);

    pGtkOffloadGetInfoRspParams = (tpSirGtkOffloadGetInfoRspParams)(limMsg->bodyptr);
    if (NULL == pGtkOffloadGetInfoRspParams)
    {
        pmmLog(pMac, LOGE, FL("Received WDA_GTK_OFFLOAD_GETINFO_RSP with NULL msg "));
        smeRspCode = eSIR_SME_GTK_OFFLOAD_GETINFO_REQ_FAILED;
    }
    else
    {
        rspStatus = pGtkOffloadGetInfoRspParams->ulStatus;
        if(rspStatus == eHAL_STATUS_SUCCESS)
        {
<<<<<<< HEAD
            pmmLog(pMac, LOGW, FL("Rcv successful response from HAL to get GTK Offload Information"));
        }
        else
        {
            pmmLog(pMac, LOGE, FL("HAL failed to get GTK Offload Information, informing SME"));
=======
            pmmLog(pMac, LOGW, FL("Rcv successful response from HAL to get GTK Offload Information\n"));
        }
        else
        {
            pmmLog(pMac, LOGE, FL("HAL failed to get GTK Offload Information, informing SME\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            smeRspCode = eSIR_SME_GTK_OFFLOAD_GETINFO_REQ_FAILED;
        }
    }

    limSendSmeRsp(pMac, eWNI_PMC_GTK_OFFLOAD_GETINFO_RSP, smeRspCode, 0, 0);
    return;
}
#endif // WLAN_FEATURE_GTK_OFFLOAD
