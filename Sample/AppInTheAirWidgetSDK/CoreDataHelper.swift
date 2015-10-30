import UIKit
import CoreData

class CoreDataHelper: NSObject {
    class var instance: CoreDataHelper {
        struct Singleton {
            static var instance = CoreDataHelper()
        }
        return Singleton.instance
    }
    
    let coordinator: NSPersistentStoreCoordinator
    let mainContext: NSManagedObjectContext
    
    private override init() {
        let modelURL = NSBundle.mainBundle().URLForResource("Model", withExtension: "momd")!
        
        let model = NSManagedObjectModel(contentsOfURL: modelURL)!
        
        coordinator = NSPersistentStoreCoordinator(
            managedObjectModel: model)
        
        let fileManager = NSFileManager.defaultManager()
        
        let libURL = fileManager.URLsForDirectory(.LibraryDirectory, inDomains: .UserDomainMask).first!
        
        let storeURL = libURL.URLByAppendingPathComponent("store.sqlite")
        
        try! coordinator.addPersistentStoreWithType(NSSQLiteStoreType, configuration: nil,
            URL: storeURL,
            options: [
                NSMigratePersistentStoresAutomaticallyOption: true,
                NSInferMappingModelAutomaticallyOption: true,
            ])
        
        mainContext = NSManagedObjectContext(concurrencyType: NSManagedObjectContextConcurrencyType.MainQueueConcurrencyType)
        mainContext.persistentStoreCoordinator = coordinator
    }
    
    func save() {
        do {
            try mainContext.save()
        } catch let error as NSError {
            print("context save error: \(error)")
        }
    }
}





