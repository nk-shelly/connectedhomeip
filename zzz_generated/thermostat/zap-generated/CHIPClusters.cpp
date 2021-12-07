/*
 *
 *    Copyright (c) 2021 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// THIS FILE IS GENERATED BY ZAP

#include "CHIPClusters.h"

#include <app-common/zap-generated/ids/Attributes.h>
#include <zap-generated/CHIPClientCallbacks.h>

namespace chip {

using namespace app::Clusters;
using namespace System;
using namespace Encoding::LittleEndian;

namespace Controller {

// TODO(#4502): onCompletion is not used by IM for now.
// TODO(#4503): length should be passed to commands when byte string is in argument list.
// TODO(#4503): Commands should take group id as an argument.

// Identify Cluster Commands
CHIP_ERROR IdentifyCluster::Identify(Callback::Cancelable * onSuccessCallback, Callback::Cancelable * onFailureCallback,
                                     uint16_t identifyTime)
{
    CHIP_ERROR err          = CHIP_NO_ERROR;
    TLV::TLVWriter * writer = nullptr;
    uint8_t argSeqNumber    = 0;

    // Used when encoding non-empty command. Suppress error message when encoding empty commands.
    (void) writer;
    (void) argSeqNumber;

    VerifyOrReturnError(mDevice != nullptr, CHIP_ERROR_INCORRECT_STATE);

    app::CommandPathParams cmdParams = { mEndpoint, /* group id */ 0, mClusterId, Identify::Commands::Identify::Id,
                                         (app::CommandPathFlags::kEndpointIdValid) };

    CommandSenderHandle sender(
        Platform::New<app::CommandSender>(mDevice->GetInteractionModelDelegate(), mDevice->GetExchangeManager()));

    VerifyOrReturnError(sender != nullptr, CHIP_ERROR_NO_MEMORY);

    SuccessOrExit(err = sender->PrepareCommand(cmdParams));

    VerifyOrExit((writer = sender->GetCommandDataIBTLVWriter()) != nullptr, err = CHIP_ERROR_INCORRECT_STATE);
    // identifyTime: int16u
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), identifyTime));

    SuccessOrExit(err = sender->FinishCommand());

    // #6308: This is a temporary solution before we fully support IM on application side and should be replaced by IMDelegate.
    mDevice->AddIMResponseHandler(sender.get(), onSuccessCallback, onFailureCallback);

    SuccessOrExit(err = mDevice->SendCommands(sender.get()));

    // We have successfully sent the command, and the callback handler will be responsible to free the object, release the object
    // now.
    sender.release();
exit:
    return err;
}

CHIP_ERROR IdentifyCluster::IdentifyQuery(Callback::Cancelable * onSuccessCallback, Callback::Cancelable * onFailureCallback)
{
    CHIP_ERROR err          = CHIP_NO_ERROR;
    TLV::TLVWriter * writer = nullptr;
    uint8_t argSeqNumber    = 0;

    // Used when encoding non-empty command. Suppress error message when encoding empty commands.
    (void) writer;
    (void) argSeqNumber;

    VerifyOrReturnError(mDevice != nullptr, CHIP_ERROR_INCORRECT_STATE);

    app::CommandPathParams cmdParams = { mEndpoint, /* group id */ 0, mClusterId, Identify::Commands::IdentifyQuery::Id,
                                         (app::CommandPathFlags::kEndpointIdValid) };

    CommandSenderHandle sender(
        Platform::New<app::CommandSender>(mDevice->GetInteractionModelDelegate(), mDevice->GetExchangeManager()));

    VerifyOrReturnError(sender != nullptr, CHIP_ERROR_NO_MEMORY);

    SuccessOrExit(err = sender->PrepareCommand(cmdParams));

    // Command takes no arguments.

    SuccessOrExit(err = sender->FinishCommand());

    // #6308: This is a temporary solution before we fully support IM on application side and should be replaced by IMDelegate.
    mDevice->AddIMResponseHandler(sender.get(), onSuccessCallback, onFailureCallback);

    SuccessOrExit(err = mDevice->SendCommands(sender.get()));

    // We have successfully sent the command, and the callback handler will be responsible to free the object, release the object
    // now.
    sender.release();
exit:
    return err;
}

// Identify Cluster Attributes
CHIP_ERROR IdentifyCluster::ReadAttributeIdentifyTime(Callback::Cancelable * onSuccessCallback,
                                                      Callback::Cancelable * onFailureCallback)
{
    app::AttributePathParams attributePath;
    attributePath.mEndpointId  = mEndpoint;
    attributePath.mClusterId   = mClusterId;
    attributePath.mAttributeId = 0x00000000;
    return mDevice->SendReadAttributeRequest(attributePath, onSuccessCallback, onFailureCallback,
                                             BasicAttributeFilter<Int16uAttributeCallback>);
}

CHIP_ERROR IdentifyCluster::SubscribeAttributeIdentifyTime(Callback::Cancelable * onSuccessCallback,
                                                           Callback::Cancelable * onFailureCallback, uint16_t minInterval,
                                                           uint16_t maxInterval)
{
    chip::app::AttributePathParams attributePath;
    attributePath.mEndpointId  = mEndpoint;
    attributePath.mClusterId   = mClusterId;
    attributePath.mAttributeId = Identify::Attributes::IdentifyTime::Id;
    return mDevice->SendSubscribeAttributeRequest(attributePath, minInterval, maxInterval, onSuccessCallback, onFailureCallback);
}

CHIP_ERROR IdentifyCluster::ReportAttributeIdentifyTime(Callback::Cancelable * onReportCallback)
{
    return RequestAttributeReporting(Identify::Attributes::IdentifyTime::Id, onReportCallback,
                                     BasicAttributeFilter<Int16uAttributeCallback>);
}

CHIP_ERROR IdentifyCluster::ReadAttributeIdentifyType(Callback::Cancelable * onSuccessCallback,
                                                      Callback::Cancelable * onFailureCallback)
{
    app::AttributePathParams attributePath;
    attributePath.mEndpointId  = mEndpoint;
    attributePath.mClusterId   = mClusterId;
    attributePath.mAttributeId = 0x00000001;
    return mDevice->SendReadAttributeRequest(attributePath, onSuccessCallback, onFailureCallback,
                                             BasicAttributeFilter<Int8uAttributeCallback>);
}

CHIP_ERROR IdentifyCluster::SubscribeAttributeIdentifyType(Callback::Cancelable * onSuccessCallback,
                                                           Callback::Cancelable * onFailureCallback, uint16_t minInterval,
                                                           uint16_t maxInterval)
{
    chip::app::AttributePathParams attributePath;
    attributePath.mEndpointId  = mEndpoint;
    attributePath.mClusterId   = mClusterId;
    attributePath.mAttributeId = Identify::Attributes::IdentifyType::Id;
    return mDevice->SendSubscribeAttributeRequest(attributePath, minInterval, maxInterval, onSuccessCallback, onFailureCallback);
}

CHIP_ERROR IdentifyCluster::ReportAttributeIdentifyType(Callback::Cancelable * onReportCallback)
{
    return RequestAttributeReporting(Identify::Attributes::IdentifyType::Id, onReportCallback,
                                     BasicAttributeFilter<Int8uAttributeCallback>);
}

CHIP_ERROR IdentifyCluster::ReadAttributeClusterRevision(Callback::Cancelable * onSuccessCallback,
                                                         Callback::Cancelable * onFailureCallback)
{
    app::AttributePathParams attributePath;
    attributePath.mEndpointId  = mEndpoint;
    attributePath.mClusterId   = mClusterId;
    attributePath.mAttributeId = 0x0000FFFD;
    return mDevice->SendReadAttributeRequest(attributePath, onSuccessCallback, onFailureCallback,
                                             BasicAttributeFilter<Int16uAttributeCallback>);
}

CHIP_ERROR IdentifyCluster::SubscribeAttributeClusterRevision(Callback::Cancelable * onSuccessCallback,
                                                              Callback::Cancelable * onFailureCallback, uint16_t minInterval,
                                                              uint16_t maxInterval)
{
    chip::app::AttributePathParams attributePath;
    attributePath.mEndpointId  = mEndpoint;
    attributePath.mClusterId   = mClusterId;
    attributePath.mAttributeId = Globals::Attributes::ClusterRevision::Id;
    return mDevice->SendSubscribeAttributeRequest(attributePath, minInterval, maxInterval, onSuccessCallback, onFailureCallback);
}

CHIP_ERROR IdentifyCluster::ReportAttributeClusterRevision(Callback::Cancelable * onReportCallback)
{
    return RequestAttributeReporting(Globals::Attributes::ClusterRevision::Id, onReportCallback,
                                     BasicAttributeFilter<Int16uAttributeCallback>);
}

} // namespace Controller
} // namespace chip
