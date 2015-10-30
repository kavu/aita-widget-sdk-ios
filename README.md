# App in the Air Widget SDK

The main purpose of the project is to allow develop third-party widgets to be embedded into App in the Air.

*This is beta version so please let us know any comments you have*

`Swift` is preferred language to build a widget, however `Objective-C` is also OK.

## Implementation ##
All widgets should implement `TripWidget` in order to be shown on the Trip Dashboard.

*There is also `AirportWidget`. Once implemented it allows to develop widget
for the Airport dashboard*

Every widget is shown in either `TripDashboard` or `AirportDashboard`
using `UICollectionView` with custom layout.

### Implement `TripWidget` ###
You can subclass any class (`NSObject` is actually enough), but must implement
`TripWidget` protocol.

There are three properties that should be set in `init` and will passed when your
widget is instantiated.
```#swift
var trip: Trip!                 //contains info about the trip (set of flights)
var flight: FlightInfo!         //contains info about the current flight
weak var dashboard: Dashboard!  //backlink to the presenting dashboard

required init(dashboard: Dashboard, trip: Trip, flight: FlightInfo) {
   self.dashboard = dashboard
   self.trip = trip
   self.flight = flight

   //any additional code here

   super.init()
}
```

#### Notes on implementation ####
* `canBeHidden` should be set to `true`.
* `canBeDisplayed` should be implemented as `private(set) dynamic var canBeDisplayed: Bool`.
If you have any data to be presenting after widget initialization set it to `true`,
or to `false` otherwise. In this case change it to `true` as soon as you have
data to show. Widget will become visible automatically.
* `widgetType` will be used for analytics + populating widget's image
`feed_widget_%s` in the editor (production only). So name your widget logo properly.
* `cellIdentifier` should be the same as your cell's `.xib` name.
* `viewController` will be called when the user taps on the widget.
You can return configured view controller or nil if you're going to present controller
yourself (e.g. with a button on the widget).
* `prepareData` is optional static method which will be called upon application launch.
Use it to populate / cache any data you need.
* you can use `AitaUserInfo.userID` in order to track the current user on your
server of you need to.

See `AitaWidget` and `TripWidget` for other methods and `ChecklistWidget` for
example implementation.

Along with widget class you'll also need the cell which will be passed to `configureCell:`
when your widget is going to be shown. For flexibility please subclass `WidgetCell`
which is `UICollectionViewCell`.

You **must** design your cell using Auto-Layout. **Cell's width may be any value
between 320 and 400 depending on the current device.**

### Reloading widget's contents ###
Anytime you need to reload your widget's appearance you should call
`Dashboard.reloadWidget:` passing self as an argument. After that the following
methods / properties will be called:

1. `cellHeight`
2. `configureCell:`

If your widget is hidden, i.e. `canBeDisplayed` is `false`, you can set it to `true`
and don't need to call `reloadWidget:`.

### Present controller ###
First of all you can present your corresponding controller using `viewController`
property in your widget. Just return non-nil value.

You can also present a controller by yourself calling `Dashboard.presentWidgetController:`,
e.g. on button tap.

Presentation style depends on `modalPresentationStyle` set to the controller:
- `.CurrentContext` using 'Push' in navigation controller. Any subsequent
controllers can be presented using navigation controller methods.
- `.Custom` presenting modally, expects `transitioningDelegate` to be set (for custom animations)
- `.FormSheet` presenting using popup controller

#### Popup presentation ####
![Popup](https://spronin.github.io/img/aita-hack/aita_popup.png)

You can also call `AAPopupViewController.showPopupWithViewController:inContainer:animated:completion:`
in order to present a controller (e.g. inside your already presented controller).

NOTE: set controller's background color to clear.

Optionally your controller can implement `AAPopupViewControllerDelegate` to customize
its presentation in popup controller.

* `popupViewControllerRightHeaderButton:` and `popupViewControllerLeftHeaderButton:`
can be used to add buttons to the header.
* `popupViewControllerPreferredWidth:forTraitCollection:` can be used to adjust
you controller's width depending on different devices and orientations (iPad / iPhone, portrait / landscape).

Check out other methods in `AAPopupViewControllerDelegate`.

### Register the widget for the dashboard ###
To be shown the widget should be added to `DashboardManager` before showing
the dashboard to the user. The best place to do so is `application:didFinishLaunchingWithOptions:`
```#swift
DashboardManager.registerWidgetClass(ChecklistWidget.self)
```

## Sample Data ##
The project contains `Model-Samples.swift`, feel free to modify the values to
those you need.

## Example ##
As an example implementation we provided a simple checklist widget.

![Checkist widget](https://spronin.github.io/img/aita-hack/checklist.png)

It uses its own CoreData storage. So you're also allowed to do so. Additionally
you can use any approach for storing data. Just don't forget to make it asynchronous.

## Adding to your project ##
This project provides configured and linked SDK and sample widget implementation.
If you want to start your project from scratch, there are few simple steps to do so:

1. Add `WidgetSDK.framework` and `WidgetSDKBundle.bundle` to your project.
2. Add `WidgetSDK.framework` to your target's Linked frameworks and libraries and Embedded binaries.
3. Add the following code to your Podfile

```
use_frameworks!
inhibit_all_warnings!

pod 'FLKAutoLayout', '~> 0.2.1'
```

## CocoaPods ##
We love and use Cocoapods in App in the Air. There is the list of libs we use.
So you can stick to them in your widget's implementation, but feel free to yours.
```
pod 'AFNetworking', '~> 2.6'
pod 'SDWebImage', '~> 3.7'
pod 'BlocksKit', '~> 2.2.5'
pod 'Google/Analytics', '~> 1.0.0'
pod 'JRSwizzle'
pod 'MBProgressHUD', '~> 0.8'
pod 'libextobjc', '~> 0.4'
pod 'DMActivityInstagram', '0.0.3'
pod 'LINEActivity', '~> 0.2.0'
pod 'WeixinActivity'
pod 'UICKeyChainStore', '~> 1.0.5'
pod 'FLKAutoLayout', '~> 0.2.1'
pod 'Branch'
pod 'GoogleAppIndexing'
pod 'GoogleMaps'
pod 'FBSDKCoreKit', '4.6.0-beta1'
pod 'FBSDKLoginKit', '4.6.0-beta1'
pod 'FBSDKShareKit', '4.6.0-beta1'

#azbo
pod 'ReactiveCocoa', '~> 2.0'
pod 'CocoaLumberjack', '~> 2.0'
pod 'AFNetworking/NSURLSession'
pod 'DFImageManager'
pod 'DFImageManager/AFNetworking'
pod 'StreamingKit'
pod 'LGAlertView'
pod 'Objection'
pod 'MRProgress'
pod 'DeviceUtil'
pod 'JJPluralForm'
pod 'SSKeychain'
pod 'UCZProgressView'
pod 'FMDB'
pod 'SMCalloutView'
pod 'DFCache'
pod 'OpenSSL', :podspec => 'https://raw.githubusercontent.com/yarry/OpenSSL-Pod/master/1.0.204.1/OpenSSL.podspec'
pod 'Mapbox-iOS-SDK', :git => 'https://github.com/yarry/route-me.git', :branch => 'develop'
```

## Submission ##
The simplest way to submit the widget is to make a fork of this repo and then send us a message to [support@appintheair.mobi](mailto:support@appintheair.mobi) with link to your implementation. Further steps includes design-review and integration of your widget to the production app.

## Contacts ##
CTO, App in the Air — Sergey Pronin [sergey.pronin@appintheair.mobi](mailto:sergey.pronin@appintheair.mobi)

CEO, App in the Air — Bayram Annakov [bayram.annakov@appintheair.mobi](mailto:bayram.annakov@appintheair.mobi)
