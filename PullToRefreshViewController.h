//
//  PullToRefreshViewController.h
//  Pulley
//
//  Created by Jason Hawkins on 5/10/11.
//  Copyright 2011 House of Legend. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "EGORefreshTableHeaderView.h"

@interface PullToRefreshViewController : UIViewController <UITableViewDataSource, UITableViewDelegate> {
    
    UITableView *_tableView;    
    EGORefreshTableHeaderView *refreshHeaderView;
    BOOL _reloading;
}

@property (nonatomic, retain) IBOutlet UITableView *tableView;
@property (assign, getter = isReloading) BOOL reloading;
@property (nonatomic, readonly) EGORefreshTableHeaderView *refreshHeaderView;

- (void)reloadTableViewDataSource;
- (void)dataSourceDidFinishLoadingNewData;

/*
     •  PullToRefreshViewController creates a generic UITableView with pull-to-refresh functionality.
     
     •  After you create your view-based project subclass of PullToRefreshViewController switch to
        Interface Builder and drag in a UITableView.  
     
     •  Connect your table view's data source and delegate from Interface Builder.
     
     •  From your subclass you'll want to implement a version of the following methods:
 
#pragma mark - Pulley delegate methods 
- (void)reloadTableViewDataSource
{
    //  Should be calling your tableviews model to reload.
    [super performSelector:@selector(dataSourceDidFinishLoadingNewData) withObject:nil afterDelay:3.0];
}

- (void)dataSourceDidFinishLoadingNewData
{
    // Should check if data reload was successful.
    [refreshHeaderView setCurrentDate]; 
    [super dataSourceDidFinishLoadingNewData];
    
    [self.tableView reloadData];
}

# pragma mark - Table View delegate methods
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    // Return the number of sections.
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return 5;
}
 
- (UITableViewCell *)tableView:(UITableView *)atableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *CellIdentifier = @"Cell";

    UITableViewCell *cell = [atableView dequeueReusableCellWithIdentifier:CellIdentifier];
    if (cell == nil) {
    cell = [[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier] autorelease];
    }

    // Configure the cell...
    cell.textLabel.text = [NSString stringWithFormat:@"Row %d", indexPath.row];    

    return cell;
}
 
*/

@end
