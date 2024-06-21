#include "ImageCommand.h"

void ImageCommand::undo()
{
    if (snapshot) {
        data = (*snapshot);
    }
    delete snapshot;
    snapshot = nullptr;
}