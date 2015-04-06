//
//  FsAlertView.m
//  FsAlertView
//
//  Created by Nestor on 09/28/2014.
//  Copyright (c) 2014 Nestor. All rights reserved.
//

#import <functional>
#import "FsAlertView.h"


typedef enum {
    FsAlertViewTypeNormal,
    FsAlertViewTypeTextField
} FsAlertViewType;

@implementation FsAlertView{
    FsAlertViewBlock cancelButtonBlock;
    FsAlertViewBlock otherButtonBlock;
    
    FsAlertViewStringBlock textFieldBlock;
}

@synthesize alertView;


- (void) alertView:(UIAlertView *)theAlertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    if (buttonIndex == 0 && cancelButtonBlock)
        cancelButtonBlock();
    else if (buttonIndex == 1 && theAlertView.tag == FsAlertViewTypeNormal && otherButtonBlock)
        otherButtonBlock();
    else if (buttonIndex == 1 && theAlertView.tag == FsAlertViewTypeTextField && textFieldBlock)
        textFieldBlock([alertView textFieldAtIndex:0].text);
    
}

- (void) alertViewCancel:(UIAlertView *)theAlertView
{
    if (cancelButtonBlock)
        cancelButtonBlock();
}

- (id) initWithTitle:(NSString*)title
             message:(NSString*)message
   cancelButtonTitle:(NSString *)cancelButtonTitle
   otherButtonTitles:(NSString *)otherButtonTitles
   cancelButtonBlock:(FsAlertViewBlock)theCancelButtonBlock
    otherButtonBlock:(FsAlertViewBlock)theOtherButtonBlock
{

    cancelButtonBlock = [theCancelButtonBlock copy];
    otherButtonBlock = [theOtherButtonBlock copy];
    
    alertView = [[UIAlertView alloc] initWithTitle:title message:message delegate:self cancelButtonTitle:cancelButtonTitle otherButtonTitles:otherButtonTitles, nil];
    alertView.tag = FsAlertViewTypeNormal;
    
    [alertView show];
    
    return self;
}

- (id) initWithTitle:(NSString*)title
             message:(NSString*)message
       textFieldHint:(NSString*)textFieldMessage
      textFieldValue:(NSString *)texttFieldValue
   cancelButtonTitle:(NSString *)cancelButtonTitle
   otherButtonTitles:(NSString *)otherButtonTitles
   cancelButtonBlock:(FsAlertViewBlock)theCancelButtonBlock
    otherButtonBlock:(FsAlertViewStringBlock)theOtherButtonBlock
{
    
    cancelButtonBlock = [theCancelButtonBlock copy];
    textFieldBlock = [theOtherButtonBlock copy];
    
    alertView = [[UIAlertView alloc] initWithTitle:title message:message delegate:self cancelButtonTitle:cancelButtonTitle otherButtonTitles:otherButtonTitles, nil];
    alertView.tag = FsAlertViewTypeTextField;

    alertView.alertViewStyle = UIAlertViewStylePlainTextInput;
    [[alertView textFieldAtIndex:0] setPlaceholder:textFieldMessage];
    [[alertView textFieldAtIndex:0] setText:texttFieldValue];
    
    [alertView show];
    
    return self;
}

@end

