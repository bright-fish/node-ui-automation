export interface CurrentBoundingRectangle {
  bottom: number;
  left: number;
  right: number;
  top: number;
}

export interface IUIAutomationElement {
  cachedProviderDescription: any;
  cachedProcessId: any;
  cachedOrientation: any;
  cachedNativeWindowHandle: any;
  cachedLocalizedControlType: any;
  cachedLabeledBy: any;
  cachedItemType: any;
  cachedItemStatus: any;
  cachedIsRequiredForForm: any;
  cachedIsPassword: any;
  cachedIsOffscreen: any;
  cachedIsKeyboardFocusable: any;
  cachedIsEnabled: any;
  cachedIsDataValidForForm: any;
  cachedIsControlElement: any;
  cachedIsContentElement: any;
  cachedHelpText: any;
  cachedHasKeyboardFocus: any;
  cachedFrameworkId: any;
  cachedFlowsTo: any;
  cachedDescribedBy: any;
  cachedCulture: any;
  cachedControlType: any;
  cachedControllerFor: any;
  cachedClassName: any;
  cachedBoundingRectangle: any;
  cachedAutomationId: any;
  cachedAriaRole: any;
  cachedAriaProperties: any;
  cachedAccessKey: any;
  cachedAcceleratorKey: any;
  cachedName: any;
  currentLabeledBy: any;
  currentProviderDescription: string;
  currentProcessId: number;
  currentOrientation: number;
  currentNativeWindowHandle: unknown[];
  currentLocalizedControlType: string;
  currentItemType: string;
  currentItemStatus: string;
  currentIsRequiredForForm: boolean;
  currentIsPassword: boolean;
  currentIsOffscreen: boolean;
  currentIsKeyboardFocusable: boolean;
  currentIsEnabled: boolean;
  currentIsDataValidForForm: boolean;
  currentIsControlElement: boolean;
  currentIsContentElement: boolean;
  currentHelpText: string;
  currentHasKeyboardFocus: boolean;
  currentFrameworkId: string;
  currentFlowsTo: unknown[];
  currentDescribedBy: unknown[];
  currentCulture: number;
  currentControlType: number;
  currentControllerFor: unknown[];
  currentClassName: string;
  currentBoundingRectangle: CurrentBoundingRectangle;
  currentAutomationId: string;
  currentAriaRole: string;
  currentAriaProperties: string;
  currentAccessKey: string;
  currentAcceleratorKey: string;
  currentName: string;

  findFirst(
    treeScope: any,
    propertyCondition: PropertyCondition
  ): IUIAutomationElement;
}

export declare interface PropertyCondition {}

export declare interface IUIAutomationTreeWalker {
  getFirstChildElement(element: IUIAutomationElement): IUIAutomationElement;
}

export class TreeScope {
  static None: any;
  static Element: any;
  static Children: any;
  static Descendants: any;
  static Parent: any;
  static Ancestors: any;
  static Subtree: any;
}

export declare class IUIAutomation {
  getRootElement(): IUIAutomationElement;
  createPropertyCondition<Value>(
    propertyId: number,
    value: Value
  ): PropertyCondition;
  rawViewWalker: IUIAutomationTreeWalker;
  controlViewWalker: IUIAutomationTreeWalker;
  contentViewWalker: IUIAutomationTreeWalker;
}
