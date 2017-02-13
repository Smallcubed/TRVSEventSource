//
//  TRVSEventSourceDelegate.h
//  TRVSEventSource
//
//  Created by Travis Jeffery on 10/9/13.
//  Copyright (c) 2013 Travis Jeffery. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TRVSEventSource;
@class TRVSServerSentEvent;

NS_ASSUME_NONNULL_BEGIN

@protocol TRVSEventSourceDelegate <NSObject>
@optional

/**
 *  Lets the delegate know that the event source has opened its connection.
 *
 *  @param eventSource The event source.
 */
- (void)eventSourceDidOpen:(TRVSEventSource *)eventSource;

/**
 *  Lets the delegate know that the event source has closed its connection.
 *
 *  @param eventSource The event source.
 */
- (void)eventSourceDidClose:(TRVSEventSource *)eventSource;

/**
 *  Lets the delegate know that the event source has received an event.
 *
 *  @param eventSource The event source.
 *  @param event       The received event.
 */
- (void)eventSource:(TRVSEventSource *)eventSource didReceiveEvent:(TRVSServerSentEvent *)event;

/**
 *  Lets the delegate know that the event source failed.
 *
 *  @param eventSource The event source.
 *  @param error       The error associated with the failure.
 */
- (void)eventSource:(TRVSEventSource *)eventSource didFailWithError:(NSError *)error;


/**
 *  Lets the delegate handle an authentication challenge.
 *
 *  @param eventSource The event source.
 *  @param challenge   The authentication challenge provided by the URL session.
 *  @param completion  A block to be called with a response to the challenge.
 */
- (void)eventSource:(TRVSEventSource *)eventSource didReceiveChallenge:(NSURLAuthenticationChallenge *)challenge completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential * _Nullable credential))completion;

@end

NS_ASSUME_NONNULL_END
