const { spawn, exec } = require('child_process');
const { PropertyIds, PatternIds } = require('microsoft-ui-automation');
const { TreeScopes } = require('microsoft-ui-automation');

function sleep(milliseconds) {
    return new Promise((resolve) => setTimeout(() => resolve(), milliseconds));
}

class AboutWindowsApplication {
    winverProcess = null;

    open() {
        if (this.winverProcess) {
            console.warn('Application "winver" already open.');
            return Promise.resolve();
        }

        this.winverProcess = spawn('winver', { shell: false });
    }

    close() {
        if (!this.winverProcess) {
            return;
        }

        this.winverProcess.kill();

        this.winverProcess = null;
    }
}


class TestApplication {
    testApplicationProcess = null;
    testApplicationWindow = null;
    automation = null;
    desktopElement = null;

    constructor(automation) {
        this.automation = automation;
    }

    async open() {
        if (this.testApplicationProcess) {
            console.warn('Application "Application.exe" already open.');
            return;
        }

        this.testApplicationProcess = spawn('../application/Application/bin/Debug/netcoreapp3.1/Application.exe');

        this.desktopElement = this.automation.getRootElement();

        const testApplicationWindowCondition = this.automation.createPropertyCondition(PropertyIds.AutomationIdPropertyId, "TestApplication");

        do {
            this.testApplicationWindow = this.desktopElement.findFirst(TreeScopes.Subtree, testApplicationWindowCondition);

            if (!this.testApplicationWindow) {
                await sleep(100);
            }
        } while (!this.testApplicationWindow);
    }



    close() {
        if (!this.testApplicationProcess) {
            return;
        }

        this.testApplicationProcess.kill();

        this.testApplicationProcess = null;
    }

    navigateToButton() {
        const listViewCondition = this.automation.createPropertyCondition(PropertyIds.NamePropertyId, "Button");
        const listViewElement = this.testApplicationWindow.findFirst(TreeScopes.Descendants, listViewCondition);

        const selectionItemProvider = listViewElement.getCurrentPattern(PatternIds.SelectionItemPatternId);

        if (!selectionItemProvider) {
            return;
        }

        selectionItemProvider.select();

    }

    navigateToText() {
        const textCondition = this.automation.createPropertyCondition(PropertyIds.NamePropertyId, "Text");
        const textElement = this.testApplicationWindow.findFirst(TreeScopes.Descendants, textCondition);

        const selectionItemProvider = textElement.getCurrentPattern(PatternIds.SelectionItemPatternId);

        if (!selectionItemProvider) {
            return;
        }

        selectionItemProvider.select();
    }

    navigateToCheckBox() { 
        const textCondition = this.automation.createPropertyCondition(PropertyIds.NamePropertyId, "Check Box");
        const textElement = this.testApplicationWindow.findFirst(TreeScopes.Descendants, textCondition);

        const selectionItemProvider = textElement.getCurrentPattern(PatternIds.SelectionItemPatternId);

        if (!selectionItemProvider) {
            return;
        }

        selectionItemProvider.select();
    }

    navigateToListView() {
        const listViewCondition = this.automation.createPropertyCondition(PropertyIds.NamePropertyId, "List View");
        const listViewElement = this.testApplicationWindow.findFirst(TreeScopes.Descendants, listViewCondition);

        const selectionItemProvider = listViewElement.getCurrentPattern(PatternIds.SelectionItemPatternId);

        if (!selectionItemProvider) {
            return;
        }

        selectionItemProvider.select();
    }

    navigateToDataView() { }

    navigateToRichTextBox() {
        const richTextBoxTabCondition = this.automation.createPropertyCondition(PropertyIds.NamePropertyId, "Document");
        const richTextBoxTabElement = this.testApplicationWindow.findFirst(TreeScopes.Descendants, richTextBoxTabCondition);

        const selectionItemProvider = richTextBoxTabElement.getCurrentPattern(PatternIds.SelectionItemPatternId);

        selectionItemProvider.select();
    }

    navigateToTree() {
        const treeTabCondition = this.automation.createPropertyCondition(PropertyIds.NamePropertyId, "Tree");
        const treeTabElement = this.testApplicationWindow.findFirst(TreeScopes.Subtree, treeTabCondition);

        const selectionItemProvider = treeTabElement.getCurrentPattern(PatternIds.SelectionItemPatternId);

        selectionItemProvider.select();
    }
}

module.exports = {
    AboutWindowsApplication,
    TestApplication
}