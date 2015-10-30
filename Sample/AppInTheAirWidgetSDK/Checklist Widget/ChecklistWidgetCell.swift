//
//  ChecklistWidgetCell.swift
//  AppInTheAirWidgetSDK
//
//  Created by Sergey Pronin on 10/23/15.
//  Copyright © 2015 App in the Air. All rights reserved.
//

import UIKit
import WidgetSDK

class ChecklistWidgetCell: WidgetCell {
    
    @IBOutlet weak var labelTitle: UILabel!
    @IBOutlet weak var labelContent: UILabel!
    @IBOutlet weak var labelItems: UILabel!

    override func awakeFromNib() {
        super.awakeFromNib()
        
        labelTitle.text = NSLocalizedString("Checklist", comment: "Checklist widget title").uppercaseString
        labelItems.text = NSLocalizedString("Check items", comment: "Checklist widget action title")
    }

}
