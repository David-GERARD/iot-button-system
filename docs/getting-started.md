# Setup instructions

Follow these steps once, before starting Session 1.

## 1. Set up your IDE

!!! note
    In this tutorial, we use the PlatformIO extension of VSCode to compile code and upload it to the Arduino. You can also use the Arduino IDE, but you will have to troubleshoot issues on your own.

!!! danger
    If you're using [Windows Subsystem for Linux (WSL)](https://learn.microsoft.com/en-us/windows/wsl/), things might be less straightforward. You can try this (unverified by us) [tutorial](https://developer.mamezou-tech.com/en/blogs/2025/04/10/develop-on-vscode-platformio-and-wsl/), and please let us know in an [issue](https://github.com/David-GERARD/iot-button-system/issues) if it worked.

1. Download and install [VSCode](https://code.visualstudio.com/).
2. In VSCode, open the Extensions tab (in the left toolbar), search and install the [PlatformIO IDE extension](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide).
3. Restart VSCode.

## 2. Fork and clone the mini project

!!! note
    This section requires minimal experience with git and GitHub. If you're not familiar with these VERY important software development tools, please check the following links before proceeding with this section.

    - [25 Basic Linux Commands](https://www.geeksforgeeks.org/linux-unix/basic-linux-commands/).
    - [Git and GitHub Introduction](https://www.w3schools.com/git/git_intro.asp?remote=github).
    - [Creating an account on GitHub](https://docs.github.com/en/get-started/start-your-journey/creating-an-account-on-github).
    - [Git Config](https://www.w3schools.com/git/git_config.asp?remote=github) (set your email as the one you used for your GitHub account).
    - [Fork a repository](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/working-with-forks/fork-a-repo).
    - [Cloning a repository](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository).

1. Go to the [project's GitHub repository home page](https://github.com/David-GERARD/iot-button-system).
2. [Optional] if you find this tutorial useful, click on the Star button in the top right corner (much appreciated).
3. Click on the Fork button in the top right corner.
4. In `Choose an owner`, choose your personal GitHub account, leave `Copy the main branch only` ticked, and click on `Create fork`.
5. In **your fork**, click on `Code` → `HTTPS`, and copy the URL.

    !!! warning
        Make sure the URL is `https://github.com/<your_username>/iot-button-system` and NOT `https://github.com/David-GERARD/iot-button-system`.

6. In VSCode, open a terminal (I would recommend using a unix-style terminal such as bash, Git bash if you are on windows, zsh...), navigate to where you want to store the project, and [clone the repository](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository).

If you want to see the entire project in VSCode, click on `File` → `Open folder...` and select the cloned folder. It contains both the PlatformIO project with the Arduino Firmware (in `firmware/`), config files for AWS IoT Core (in `infra/`), and AWS Lambda functions coded in Python (in `lambdas/`).

## 3. Add a course educator as a collaborator

!!! note
    Each task you complete will be submitted as a pull request and reviewed by one of the course educators (see the branch/pull request workflow described at the start of every task). For them to be able to review your pull requests, they need to be added as a collaborator on **your fork**.

1. In **your fork** on GitHub, go to `Settings` → `Collaborators and teams`.
2. Click on `Add people`, and search for the GitHub username your course educator gave you.
3. Select the `Read` role — this is enough to view your code and review pull requests.
4. Click `Add <username> to this repository`.

## 4. Open the Arduino firmware in PlatformIO

1. In VSCode, click on the PlatformIO tab (in the left toolbar).
2. In `Project Tasks`, click on `Pick a Folder` (you might need to scroll down). Navigate to the cloned repository, and inside it, select the folder `firmware/`.

## 5. Gather your hardware

Make sure you have the following before starting Session 1:

- Arduino MKR WiFi 1010.
- MKR Connector Carrier.
- LED kit.
- Push button kit.

## 6. Set up your AWS account

!!! warning
    The free tier of AWS lasts 6 months, and an email address can only be used once to create an AWS account. If you have an AWS account but the free tier expired, create a new one using a different address (you can create a free Gmail account if need be).

!!! tip
    For the group project, it is best that you use a single AWS account, and have its owner [create IAM users](https://docs.aws.amazon.com/IAM/latest/UserGuide/id_users_create.html) for each team member. Make sure to grant these IAM users the right permissions to perform their required tasks.

If need be, [create a new AWS account](https://docs.aws.amazon.com/iot/latest/developerguide/setting-up.html) and IAM users for each team member (and yourself — it is good practice to only use root access for permission management).

You're all set. Before diving into Session 1, read the [Development Workflow](development-workflow.md) page — it explains the branch/commit/pull request/tag cycle you'll repeat for every task.
