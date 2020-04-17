// 本文件相关 头文件
#include "mainwindow.h"
#include "ui_mainwindow.h"

// 库 头文件
#include <QDir>
#include "opencv2/opencv.hpp"

// 系统 头文件
#include <string>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 点击按钮 功能
void MainWindow::on_btn_open_clicked()
{
    // 当前目录为 同等级文件夹下 debug  内容
    QString cur_dir = QDir::currentPath();
    ui->te_log->append(cur_dir + "<br>");



    std::string img_filename = "../test/test_panda.png";
    cv::Mat img_src;

    try {
        img_src = cv::imread(img_filename);
        cv::imshow("src image",img_src);
        ui->te_log->append("Read image OK!");

    } catch (...) {
        ui->te_log->append("Read image error!");

    }


}
