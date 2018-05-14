#include "DataModel.h"
#include "DataPort.h"

using namespace NodeEditor;
using namespace QtNodes;

DataModel::DataModel()
{
}

DataModel::~DataModel()
{
    // .lol.
}

DataModel* DataModel::Copy()
{
    auto* model = new DataModel(*this);
    CopyPortTypes(*model);

    for (const auto& inputType : m_inputTypes) { model->AddInput(new DataPort(inputType)); }

    for (const auto& outputType : m_outputTypes) { model->AddOutput(new DataPort(outputType)); }

    return model;
}

DataModel::DataModel(const DataModel& other)
    : NodeDataModel()
  , m_caption(other.m_caption)
  , m_isCaptionVisible(other.m_isCaptionVisible)
  , m_name(other.m_name)
{
}

void DataModel::CopyPortTypes(DataModel& destinationModel)
{
    for (auto input : m_inputTypes) { destinationModel.m_inputTypes.push_back(input); }
    for (auto output : m_outputTypes) { destinationModel.m_outputTypes.push_back(output); }
}

unsigned DataModel::nPorts(PortType portType) const
{
    switch (portType)
    {
    case PortType::In:
        return m_inputs.size();
    case PortType::Out:
        return m_outputs.size();
    default:
        return 0;
    }
}

NodeDataType DataModel::dataType(PortType portType, PortIndex portIndex) const
{
    switch (portType)
    {
    case PortType::In:
        return m_inputs[portIndex]->type();
    case PortType::Out:
        return m_outputs[portIndex]->type();
    default:
        return NodeDataType();
    }
}

std::shared_ptr<NodeData> DataModel::outData(PortIndex port)
{
    auto* p = dynamic_cast<NodeData*>(m_outputs[port]);
    return std::shared_ptr<NodeData>(p);
}

void DataModel::setInData(std::shared_ptr<NodeData> nodeData, PortIndex port)
{
}

QWidget* DataModel::embeddedWidget() { return nullptr; }

void DataModel::AddInput(DataPort* const & port) { m_inputs.push_back(port); }

void DataModel::AddOutput(DataPort* const & port) { m_outputs.push_back(port); }

void DataModel::AddInputType(NodeDataType const& type) { m_inputTypes.push_back(type); }

void DataModel::AddOutputType(NodeDataType const& type) { m_outputTypes.push_back(type); }
