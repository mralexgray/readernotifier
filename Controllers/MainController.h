//
//  MainController.h
//  GoogleReader
//
//  Created by Eli Dourado on 12/8/05.
//  Modified by Troels Bay (troelsbay@troelsbay.eu)
//
//

#import <Cocoa/Cocoa.h>
#import <Growl/Growl.h>
#import <IOKit/IOKitLib.h>
#import "IPMNetworkManagerDelegate.h"

@class IPMNetworkManager;
@class NetParam;

@interface MainController : NSObject<GrowlApplicationBridgeDelegate, IPMNetworkManagerDelegate> {
    IBOutlet NSSecureTextField * passwordField;
    IBOutlet NSTextField * usernameField;
    IBOutlet NSTextField * addNewFeedUrlField;
	IBOutlet NSTextField * torrentCastFolderPath;
	IBOutlet NSMenu * GRMenu;
	IBOutlet NSWindow * preferences; //preference window
	IBOutlet NSWindow * addfeedwindow; //addfeed window
	
    NSTimer * mainTimer;
	NSTimer * lastCheckTimer;
	
	NSStatusItem * statusItem;
	NSError * xmlError;
	NSUserDefaults * prefs;
	
	NSMutableArray * titles;
	NSMutableArray * sources;
	NSMutableArray * user;
	NSMutableArray * links;
	NSMutableArray * ids;
	NSMutableArray * feeds;	
	NSMutableArray * summaries;	
	NSMutableArray * torrentcastlinks;
	NSMutableArray * results;
	NSMutableArray * lastIds;
	NSMutableArray * newItems;
	NSDictionary * normalAttrsDictionary;
	NSDictionary * smallAttrsDictionary;
	
	NSString * storedSID;
	NSString * torrentCastFolderPathString;
	NSString * currentToken;
	
	NSSound * theSound;
	NSImage * unreadItemsImage;
	NSImage * highlightedImage;
	NSImage * nounreadItemsImage;
	NSImage * errorImage;
	
	IPMNetworkManager * networkManager;
	
	BOOL isLeopard;
	BOOL currentlyFetchingAndUpdating;
	BOOL moreUnreadExistInGRInterface;
	BOOL needToRemoveNormalButtons;
	
	NSInteger totalUnreadCount;
	NSInteger lastCheckMinute;
	NSInteger endOfFeedIndex;
}

- (void)downloadFile:(NSString *)filename atUrl:(NSString *)url;
- (NSAttributedString *)makeAttributedStatusItemString:(NSString *)text;
- (NSAttributedString *)makeAttributedMenuStringWithBigText:(NSString *)bigtext andSmallText:(NSString *)smalltext;
- (void)addFeed:(NSString *)url;
- (void)displayAlertWithHeader:(NSString *)headerText andBody:(NSString *)bodyText;
- (void)displayMessage:(NSString *)message;
- (NSString *)grabUserNo;
- (NSString *)loginToGoogle;
- (void)getTokenFromGoogle;
- (void)removeOneFeedFromMenu:(NSInteger)index;
- (void)timer:(NSTimer *)timer;
- (void)getUnreadCountWithDeferredCall:(NetParam *)dc;
- (void)retrieveGoogleFeed;
- (void)updateMenu;
- (void)setTimeDelay:(NSInteger)x;
- (NSString *)getLabel;
- (void)errorImageOn;
- (NSString *)getURLPrefix;
- (void)announce;
- (NSString *)getUserPasswordFromKeychain;
- (void)growlNotificationWasClicked:(id)clickContext;
- (NSDictionary *)registrationDictionaryForGrowl;
- (void)setupEventHandlers;
- (void)handleOpenLocationAppleEvent:(NSAppleEventDescriptor *)event withReplyEvent:(NSAppleEventDescriptor *)reply;
- (void)createLastCheckTimer;
- (void)displayLastTimeMessage:(NSString *)message;
- (void)displayTopMessage:(NSString *)message;
- (void)lastTimeCheckedTimer:(NSTimer *)timer;
- (void)selectTorrentCastFolderEnded:(NSOpenPanel *)panel returnCode:(int)returnCode contextInfo:(void *)contextInfo;
- (void)checkNowWithDelayDetached:(NSNumber *)delay;
- (void)markResultsAsReadDetached;
- (void)markOneAsReadDetached:(NSNumber *)aNumber;
- (void)markAllAsReadDetached;
- (void)markOneAsStarredDetached:(NSNumber *)aNumber;
- (void)awakenFromSleep;


- (IBAction)launchSite:(id)sender;
- (IBAction)markAllAsRead:(id)sender;
- (IBAction)launchLink:(id)sender;
- (IBAction)doOptionalActionFromMenu:(id)sender;
- (IBAction)launchErrorHelp:(id)sender;
- (IBAction)checkGoogleAuth:(id)sender;
- (IBAction)openPrefs:(id)sender;
- (IBAction)checkNow:(id)sender;
- (IBAction)openAddFeedWindow:(id)sender;
- (IBAction)addFeedFromUI:(id)sender;
- (IBAction)selectTorrentCastFolder:(id)sender;

@end
