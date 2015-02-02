#import <Foundation/Foundation.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSString.h>

@interface Book : NSObject 
{
    @property NSString *title;
    @property NSString *author;
    @property int       yearPub;
}
-(void) setTitle:(NSString *) newTitle;
-(void) setAuthor:(NSString *) newAuthor;
-(void) setYearPub:(int) newYearPub;
-(NSString *)title;
-(NSString *)author;
-(int)yearPub;
-(void)printBook;
@end

@implementation Book
@synthesize title, author, yearPub;

- (void) setTitle: (NSString *) newTitle
{
    title = [[NSString alloc]initWithString: newTitle];
}

- (void) setAuthor: (NSString *) newAuthor
{
    author = [[NSString alloc]initWithString: newAuthor];
}

- (void) setYearPub: (int) newYearPub
{
    yearPub = newYearPub;
}

-(void) printBook
{
	NSLog(@"Title: %@, Author: %@, Year: %d", title, author, yearPub);
}
@end

int main (int argc, const char * argv[]) {
    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];

    Book *book = [[Book alloc] init];

    [book setTitle:@"My First Book"];
    [book setAuthor:@"Shail"];
    [book setYearPub:@1983];
	[book printBook];

    [book release];
    [pool drain];
    return 0;
}