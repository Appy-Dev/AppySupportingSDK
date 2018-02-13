#import <UIKit/UIKit.h>
#import "GCDAsyncSocket.h"
#import "GCDAsyncUdpSocket.h"

#pragma mark - SocketHandler

typedef void (^SocketHandlerStandardBlock)(id socketHandler);
typedef void (^SocketHanderResponseBlock)(id socketHandler, NSData *data, NSString *response);

typedef NS_ENUM (NSInteger, kSocketHandlerErrorCode) {
    kSocketHandlerNoError,
    kSocketHandlerFailedToRead,
    kSocketHandlerFailedToWrite,
    kSocketHandlerFailedToBind,
    kSocketHandlerFailedToEnableUDPBroadcast,
    kSocketHandlerDisconnectedByPeer,
    kSocketHandlerConnectionError,
    kSocketHandlerTimeout,
    kSocketHandlerTerminated
};

@interface AbstractSocketHandler : NSObject

@property (nonatomic) NSInteger timeout;
@property (nonatomic) NSInteger tag;
@property (nonatomic) NSInteger errorCode;
@property (nonatomic, strong) SocketHandlerStandardBlock onConnectedBlock;
@property (nonatomic, strong) SocketHandlerStandardBlock onTerminatedBlock;
@property (nonatomic, strong) SocketHandlerStandardBlock onSendDataBlock;
@property (nonatomic, strong) SocketHanderResponseBlock onReceivedResponseBlock;
@property (nonatomic, strong) NSMutableArray *responses;

- (void)terminate;
- (BOOL)hasError;
- (NSInteger)totalResponses;
- (NSString *)address;

@end

@interface TCPSocketHandler : AbstractSocketHandler <GCDAsyncSocketDelegate, GCDAsyncUdpSocketDelegate>

+ (TCPSocketHandler *)createWithAddress:(NSString *)address port:(NSInteger)port;
- (void)connectAndWrite:(NSString *)message;
- (void)write:(NSString *)message;
- (void)read;
- (void)connect;
- (BOOL)isDisconnected;

@end

@interface UDPSocketHandler : AbstractSocketHandler <GCDAsyncUdpSocketDelegate>

+ (UDPSocketHandler *)createWithAddress:(NSString *)address port:(NSInteger)port;
- (void)send:(NSString *)message;
- (void)broadcast:(NSString *)message;
- (void)listening;

@end
