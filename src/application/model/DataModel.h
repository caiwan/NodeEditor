#pragma once

#include <nodes/NodeDataModel>

namespace NodeEditor
{
	class DataPort;

	class DataModel : public QtNodes::NodeDataModel
	{
	public:

		DataModel();
		DataModel& operator=(const DataModel& other) = delete;
		~DataModel();

		DataModel* Copy();

		// overrides - schema
		QString caption() const override { return m_caption; }

		bool captionVisible() const override { return m_isCaptionVisible; }

		QString name() const override { return m_name; }

		// overrides - ports 
		unsigned int nPorts(QtNodes::PortType portType) const override;

		QtNodes::NodeDataType dataType(QtNodes::PortType portType, QtNodes::PortIndex portIndex) const override;

		std::shared_ptr<QtNodes::NodeData> outData(QtNodes::PortIndex port) override;

		void setInData(std::shared_ptr<QtNodes::NodeData> nodeData, QtNodes::PortIndex port) override;
		QWidget* embeddedWidget() override;

		// 
		void AddInput(DataPort* const& port);
		void AddOutput(DataPort* const& port);

		void AddInputType(QtNodes::NodeDataType const& type);
		void AddOutputType(QtNodes::NodeDataType const& type);

		//
		QString GetCaption() const { return m_caption; }
		void SetCaption(const QString& caption) { m_caption = caption; }
		bool IsIsCaptionVisible() const { return m_isCaptionVisible; }
		void SetIsCaptionVisible(const bool isCaptionVisible) { m_isCaptionVisible = isCaptionVisible; }
		QString GetName() const { return m_name; }
		void SetName(const QString& name) { m_name = name; }
		QList<DataPort*> GetInputs() const { return m_inputs; }
		void SetInputs(const QList<DataPort*>& dataPorts) { m_inputs = dataPorts; }
		QList<DataPort*> GetOutputs() const { return m_outputs; }
		void SetOutputs(const QList<DataPort*>& dataPorts) { m_outputs = dataPorts; }

	private:
		DataModel(const DataModel& other);
		void CopyPortTypes(DataModel& destination);

		QString m_caption;
		bool m_isCaptionVisible;
		QString m_name;

		QList<DataPort*> m_inputs;
		QList<DataPort*> m_outputs;

		QList<QtNodes::NodeDataType> m_inputTypes;
		QList<QtNodes::NodeDataType> m_outputTypes;
	};
}
