#include  "DataPort.h"

using namespace NodeEditor;
using namespace QtNodes;

DataPort::DataPort(const NodeDataType& nodeDataType)
    : m_nodeDataType(nodeDataType)
{
}

DataPort::DataPort(const DataPort& other)
    : QtNodes::NodeData(other)
  , m_nodeDataType(other.m_nodeDataType)
{
}

DataPort::DataPort(DataPort&& other) noexcept
    : QtNodes::NodeData(std::move(other))
  , m_nodeDataType(std::move(other.m_nodeDataType))
{
}

DataPort& DataPort::operator=(const DataPort& other)
{
    if (this == &other)
        return *this;
    QtNodes::NodeData::operator =(other);
    m_nodeDataType = other.m_nodeDataType;
    return *this;
}

DataPort& DataPort::operator=(DataPort&& other) noexcept
{
    if (this == &other)
        return *this;
    QtNodes::NodeData::operator =(std::move(other));
    m_nodeDataType = std::move(other.m_nodeDataType);
    return *this;
}

DataPort::~DataPort()
{
}
