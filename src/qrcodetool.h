#ifndef QRCODETOOL_H
#define QRCODETOOL_H

#include <QObject>
#include <QString>
#include <QImage>
#include <QPainter>
#include <QQuickImageProvider>
#include <QUrl>
#include <vector>
#include "qrcodegen.hpp"

using qrcodegen::QrCode;

class QrCodeProvider : public QQuickImageProvider
{
public:
    QrCodeProvider() : QQuickImageProvider(QQuickImageProvider::Image) {}

    QImage requestImage(const QString &id, QSize *size, const QSize &/*requestedSize*/) override {
        QString text = QUrl::fromPercentEncoding(id.toUtf8());
        if (text.isEmpty()) return QImage();

        // Use the low-level data segment to avoid exceptions if possible, 
        // or just ensure we handle the result safely.
        QByteArray utf8 = text.toUtf8();
        std::vector<qrcodegen::QrSegment> segs = qrcodegen::QrSegment::makeSegments(utf8.constData());
        QrCode qr = QrCode::encodeSegments(segs, QrCode::Ecc::MEDIUM);
        
        int scale = 10;
        int border = 4;
        int size_px = (qr.getSize() + border * 2) * scale;
        
        QImage img(size_px, size_px, QImage::Format_RGB32);
        img.fill(Qt::white);
        
        QPainter p(&img);
        p.setBrush(Qt::black);
        p.setPen(Qt::NoPen);
        
        for (int y = 0; y < qr.getSize(); y++) {
            for (int x = 0; x < qr.getSize(); x++) {
                if (qr.getModule(x, y)) {
                    p.drawRect((x + border) * scale, (y + border) * scale, scale, scale);
                }
            }
        }
        
        if (size) *size = img.size();
        return img;
    }
};

#endif // QRCODETOOL_H
