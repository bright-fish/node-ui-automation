const { spawn } = require('child_process');

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

module.exports = {
    AboutWindowsApplication
}