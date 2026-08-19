![](docs/images/ucl-logo.svg)
# iot-button-system

Source repository for the UCL EEE IoT course website and mini project.

📖 **Course website:** [david-gerard.github.io/iot-button-system/home/](https://david-gerard.github.io/iot-button-system/home/)

## Repository structure
```bash
iot-button-system/
|---docs/ # Source for the course website (MkDocs)
|---firmware/ # Contains Arduino code for the MKR WIFI 10101 board
|---infra/ # Contains AWS IOT config files
|---lambdas/ # Contains AWS Lambda function code written in python
```

## Getting the code

1. Go to the [project's GitHub repository home page](https://github.com/David-GERARD/iot-button-system).
2. Click on the Fork button in the top right corner, choose your personal GitHub account, and click `Create fork`.
3. In **your fork**, click on `Code` → `HTTPS`, and copy the URL.
4. Clone it locally:
    ```bash
    git clone <the URL you copied>
    ```

## Building the documentation site locally

The course website is built from `docs/` using [MkDocs](https://www.mkdocs.org/) with the [Material for MkDocs](https://squidfunk.github.io/mkdocs-material/) theme. Dependencies are managed with [uv](https://docs.astral.sh/uv/).

1. [Install uv](https://docs.astral.sh/uv/getting-started/installation/) if you don't already have it.
2. From the repository root, sync the environment:
    ```bash
    uv sync
    ```
3. Serve the site locally with live reload:
    ```bash
    uv run mkdocs serve
    ```
4. Open [http://127.0.0.1:8000](http://127.0.0.1:8000).

## Contributors

- [David-GERARD](https://github.com/David-GERARD)
